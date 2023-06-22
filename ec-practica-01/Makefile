all: a.out b.out c.out

a.out:
	gcc p2-1.c -o a.out

b.out:
	gcc p2-2.c -o b.out

c.out:
	gcc p2-3.c -o c.out

clean:
	rm a.out b.out c.out

test: c.out
	bash test.sh
