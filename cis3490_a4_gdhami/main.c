/*
Gurtej Dhami
0969863
03/29/2020
CIS 3490 Assignment 4
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "DynamicOBST.h"
#include "GreedyOBST.h"
/*
The main file executes both the Dynamic Optimal Binary Search Tree as well as the Greedy Optimal BInary Search Tree. The user string for both algorithms is also scanned here
*/

int main(int argc, char const *argv[])
{
	FILE *file;
	char userStr[25];
	char userStr2[25];

	if ((argc < 2) || (argc > 2))
	{
		printf("Incorrect input\nShould be ./a4 <data file for Assignment 4>\n");
		return(-1);
	}
	printf("Please enter a string for Dynamic OBST:\n");
	scanf("%s", userStr);

	
	//Dynamic OBST Algorithm
	printf("\nDynamic OBST:\n");
	file = fopen(argv[1], "r");
	DynamicOBST(file, userStr);

	printf("\nPlease enter a string for Greedy OBST:\n");
	scanf("%s", userStr2);


	//Greedy OBST Algorithm
	printf("\nGreedy OBST:\n");
	file = fopen(argv[1], "r");
	GreedyOBST(file, userStr2);
	
	return 0;
}
