/*
Gurtej Dhami
0969863
CIS 3490 A3
*/

#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/timeb.h>

#include "P21.h"
#include "P22.h"
#include "P23.h"
/*
The main function parses the data5.txt file and executes the brute force
string search as well as the Horspool and Boyer-Moore algorithms. The main function also
prints the final string comparison count and execution time for the bruteforce method only.
*/
void printFunction(float num, int match);

int main(int argc, char const *argv[])
{
	FILE *file;
	int BFSearchCount = 0;
	char userStr[25];

	struct timeb timeStart;
	struct timeb timeEnd;

	float BFtime;

	if ((argc < 2) || (argc > 2))
	{
		printf("Incorrect input\nShould be ./part1 <data file for part 1>\n");
		return(-1);
	}
	printf("Please enter a string:\n");
	scanf("%s", userStr);

	
	//Execute Brute Force Algorithm
	printf("\nBrute Force:\n");
	ftime(&timeStart);
	file = fopen(argv[1], "r");
	BFSearchCount = bruteforceString(file, userStr);
	fclose(file);
	ftime(&timeEnd);

	BFtime = (timeEnd.millitm - timeStart.millitm)+ (timeEnd.time - timeStart.time)*1000;
	printFunction(BFtime, BFSearchCount);

	//Execute Horspool Algorithm
	file = fopen(argv[1], "r");
	horspoolString(file, userStr);
	fclose(file);
	
	//Execute Boyer Moore Algorithm
	file = fopen(argv[1], "r");
	boyermooreString(file, userStr);
	fclose(file);

	
	return 0;
}

void printFunction(float time, int match)
{
	printf("Execution Time: %f mS\n",time);
	printf("Number of string matches: %d\n", match);
}

