#!/bin/bash

set -e

export START_PATH="$(pwd)"
export SCRIPT_PATH="$(dirname $0)"
export GIT_ROOT_PATH="$SCRIPT_PATH/.."

export BUILD_DIR="$SCRIPT_PATH/build"
export BUILD_LOG="$BUILD_DIR/log"
export BUILD_TEST_BINARY="$BUILD_DIR/test"

export GTEST_DIR="$SCRIPT_PATH/lib/googletest"
export GTEST_ARCHIVE="$BUILD_DIR/libgtest.a"
export GTEST_OBJECT="$BUILD_DIR/gtest-all.o"

export SOURCE_DIR="$SCRIPT_PATH/src"

{
	mkdir -p "$BUILD_DIR"
	mkdir -p "$GTEST_DIR"
	mkdir -p "$SOURCE_DIR"

	touch "$BUILD_LOG"

	echo ""
	echo Build started $(date)

	echo Updating googletest git source code
	cd "$GIT_ROOT_PATH"
	git submodule update --init
	cd "$START_PATH"

	echo Building and linking googletest
	g++ -I "$GTEST_DIR/include" -I "$GTEST_DIR" -c "$GTEST_DIR/src/gtest-all.cc" \
		-o "$GTEST_OBJECT"

	ar -rv "$GTEST_ARCHIVE" "$GTEST_OBJECT"

	echo Building acm test runner >> $BUILD_LOG
	g++ -I "$GTEST_DIR/include" -I "$SOURCE_DIR/core" -I "$SOURCE_DIR/bfs" \
		-pthread \
		"$SOURCE_DIR/core/core.cpp" \
		"$SOURCE_DIR/bfs/bfs.cpp" "$SOURCE_DIR/bfs/bfs.test.cpp" \
		"$SOURCE_DIR/main-test.cpp" \
		"$GTEST_ARCHIVE" \
		-o "$BUILD_TEST_BINARY"
} >> "$BUILD_LOG" && "./$BUILD_TEST_BINARY"