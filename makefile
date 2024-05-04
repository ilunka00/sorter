all: compile clean
compile: main.c
	gcc -o sorter main.c -w

clean:
	-rm sorter