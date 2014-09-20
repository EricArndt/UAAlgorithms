export BUILD_DIR='bin'
export GTEST_DIR='gtest'

mkdir -p $BUILD_DIR

# Build gtest
g++ -isystem ${GTEST_DIR}/include -I${GTEST_DIR} \
	-pthread -c ${GTEST_DIR}/src/gtest-all.cc \
	-o ${BUILD_DIR}/gtest-all.o

ar -rv ${BUILD_DIR}/libgtest.a ${BUILD_DIR}/gtest-all.o > /dev/null

# Build algorithms against gtest and product test binary
g++ -isystem ${GTEST_DIR}/include -pthread \
	-Iincrement \
	increment/increment.cpp \
	increment/increment.test.cpp \
	main-test.cpp \
	${BUILD_DIR}/libgtest.a -o ${BUILD_DIR}/unittest

# Copy the test binary to the root dir
for binary in unittest{,.exe}; do
	cp bin/$binary . 2> /dev/null
done

exit 0