compile:
	mkdir out
	gcc src/cadenas.c -o out/1.out
	gcc src/info.c -o out/2.out
clean:
	rm -rf out
test: clean compile
	bash tests/alltests.sh
