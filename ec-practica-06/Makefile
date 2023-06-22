compile:
	mkdir out
	gcc src/p6-1.c -o out/1.out
	gcc src/p6-2.c -o out/2.out
	gcc src/p6-3.c -o out/3.out
	gcc src/p6-4.c -o out/4.out
clean:
	rm -rf out
test: clean compile
	bash tests/alltests.sh
