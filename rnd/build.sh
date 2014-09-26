export BUILD_DIR='build'
export BUILD_LOG='build/log'
export GTEST_DIR='lib/googletest'
export GTEST_ARCHIVE="$BUILD_DIR/libgtest.a"
export GTEST_OBJECT="$BUILD_DIR/gtest-all.o"

g++ -I ${GTEST_DIR}/include -I ${GTEST_DIR} -c ${GTEST_DIR}/src/gtest-all.cc -o $GTEST_OBJECT 2> $BUILD_LOG
ar -rv $GTEST_ARCHIVE $GTEST_OBJECT 2> $BUILD_LOG