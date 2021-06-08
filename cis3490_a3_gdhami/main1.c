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

#include "P11.h"
#include "P12.h"

/*
The main function executes the brute force
anagram count as well as the pre sort anagram count. The main function also
prints the final anagram count and execution time for both methods.
*/
void printFunction(float num, int Anagram);

int main(int argc, char const *argv[])
{
	FILE *file;
	int BFAnagramCount = 0;
	int PSAnagramCount = 0;
	long int userN = 0;

	struct timeb timeStart;
	struct timeb timeEnd;

	float BFtime;

	if ((argc < 2) || (argc > 2))
	{
		printf("Incorrect input\nShould be ./part1 <data file for part 1>\n");
		return(-1);
	}
	printf("Please enter a number:\n");
	scanf("%ld", &userN);

	
	//Execute Brute Force Algorithm
	ftime(&timeStart);
	file = fopen(argv[1], "r");
	BFAnagramCount = bruteforce(file, userN);
	fclose(file);
	ftime(&timeEnd);

	BFtime = (timeEnd.millitm - timeStart.millitm)+ (timeEnd.time - timeStart.time)*1000;
	printf("\nBrute Force:\n");
	printFunction(BFtime, BFAnagramCount);

	//Execute Pre Sort Algorithm
	printf("\nPresort sort:\n");
	file = fopen(argv[1], "r");
	PSAnagramCount = preSort(file, userN);
	fclose(file);

	printf("Number of Anagrams: %d\n", PSAnagramCount);
	
	return 0;
}

void printFunction(float time, int Anagram)
{
	printf("Execution Time: %f mS\n",time);
	printf("Number of Anagrams: %d\n", Anagram);
}

