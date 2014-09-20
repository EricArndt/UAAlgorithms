compile_body=''
for alg in `ls src`; do
	impl_file="src/$alg/$alg.cpp"
	test_file="src/$alg/$alg.test.cpp"
	if [ -f "$impl_file" ] && [ -f "$test_file" ]; then
		compile_body="$compile_body -Isrc/$alg $impl_file $test_file"
	else
		echo "$alg appears incomplete; skipping"
	fi
done

g++ -Iinclude $compile_body main-test.cpp lib/libgtest.a -o bin/unittest