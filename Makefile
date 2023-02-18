all:
	gcc -Wall ex1.c -o ex1

run:
	./ex1 test.txt out.txt

# yes "ola mundo" | head -n 100000 > input.txt

# time:
# 	time ./ex1 input.txt out

clean:
	rm -rf out.txt