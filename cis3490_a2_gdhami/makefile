all: main1 main2

main1: 
	gcc -o part1 main.c P11.c P12.c -std=c99 -Wall

main2: 
	gcc -o part2 main2.c P21.c P22.c -std=c99 -Wall

tar:
	tar -cvf cis3490_a2_gdhami.tar makefile design.pdf main.c main2.c P11.c P11.h P12.c P12.h P21.c P21.h P22.c P22.h readme.txt

.PHONY: clean
clean:
	rm -rf *o part1 part2
