export BUILD_DIR='build'
export BUILD_LOG='build/log'
export GTEST_DIR='lib/googletest'
export GTEST_ARCHIVE="$BUILD_DIR/libgtest.a"
export GTEST_OBJECT="$BUILD_DIR/gtest-all.o"
export SOURCE_DIR='src'
export ROOT_DIR='..'

export start_dir=$(pwd)

mkdir -p $BUILD_DIR
mkdir -p $GTEST_DIR
mkdir -p $SOURCE_DIR

touch $BUILD_LOG

{
	echo ""
	echo Build started $(date)

	echo Updating googletest git source code
	cd $ROOT_DIR
	git submodule update --init
	cd $start_dir

	echo Building and linking googletest
	g++ -I ${GTEST_DIR}/include -I ${GTEST_DIR} -c ${GTEST_DIR}/src/gtest-all.cc \
		-o $GTEST_OBJECT

	ar -rv $GTEST_ARCHIVE $GTEST_OBJECT

	echo Building acm test runner >> $BUILD_LOG
	g++ -I $GTEST_DIR/include -I $SOURCE_DIR/core -I $SOURCE_DIR/bfs \
		-pthread \
		$SOURCE_DIR/core/core.cpp \
		$SOURCE_DIR/bfs/bfs.cpp $SOURCE_DIR/bfs/bfs.test.cpp \
		$SOURCE_DIR/main-test.cpp \
		$GTEST_ARCHIVE \
		-o test
} >> $BUILD_LOG && ./test