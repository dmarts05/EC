compile:
	mkdir out
	gcc src/p5-1.c -o out/1.out
	gcc src/p5-2.c -o out/2.out
	gcc src/p5-3.c -o out/3.out
	gcc src/p5-4.c -o out/4.out
	gcc src/p5-5.c -o out/5.out
	gcc src/p5-6.c -o out/6.out
	gcc src/p5-7.c -o out/7.out
clean:
	rm -rf out
test: clean compile
	bash tests/alltests.sh
