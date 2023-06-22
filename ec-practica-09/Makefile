compile:
	mkdir out
	gcc src/p9-1.c -o out/1.out
	gcc src/p9-2.c -o out/2.out -lm
	gcc src/p9-3.c -o out/3.out
	gcc src/p9-4.c -o out/4.out -lm
clean:
	rm -rf out
test: clean compile
	bash tests/alltests.sh
