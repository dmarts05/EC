compile:
	mkdir out
	gcc src/p3-1.c -o out/1.out
	gcc src/p3-2.c -o out/2.out
	gcc src/p3-3.c -o out/3.out
	gcc src/p3-4.c -o out/4.out
	gcc src/p3-5.c -o out/5.out
	gcc src/p3-6.c -o out/6.out
	gcc src/p3-7.c -o out/7.out
	gcc src/p3-8.c -o out/8.out
	gcc src/p3-9.c -o out/9.out

clean:
	rm -rf out
test: clean compile
	bash tests/alltests.sh