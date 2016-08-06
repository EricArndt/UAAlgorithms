
run_test() {
	binary=''
	for f in `find bin -name 'unittest*'`; do
		if [ -f "$f" ]; then
			binary="$f"
		fi
	done

	if [ "$binary" != "" ]; then
		$binary
	elif [ "$1" == "initial" ]; then
		echo "Could not find unittest binary in bin; trying a build"
		./build.sh && run_test
	fi
}

run_test initial