all: main

main: 
	gcc -o a4 main.c DynamicOBST.c GreedyOBST.c -std=c99 -Wall

tar:
	tar -cvf cis3490_a4_gdhami.tar makefile main.c DynamicOBST.c DynamicOBST.h GreedyOBST.c GreedyOBST.h readme.txt Data7.txt

.PHONY: clean
clean:
	rm -rf *o a4
