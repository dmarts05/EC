compile:
	mkdir out
	gcc src/p4-1.c -o out/1.out
	gcc src/p4-2.c -o out/2.out
	gcc src/p4-3.c -o out/3.out
	gcc src/p4-4.c -o out/4.out
	gcc src/p4-5.c -o out/5.out
	gcc src/p4-6.c -o out/6.out
clean:
	rm -rf out
test: clean compile
	bash tests/alltests.sh
