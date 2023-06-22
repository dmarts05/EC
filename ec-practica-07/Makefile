compile:
	mkdir out
	gcc src/p7-1.c -o out/1.out
	gcc src/p7-2.c -o out/2.out
	gcc src/p7-3.c -o out/3.out
clean:
	rm -rf out
test: clean compile
	bash tests/alltests.sh
