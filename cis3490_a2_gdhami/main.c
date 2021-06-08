/*
Gurtej Dhami
0969863
CIS 3490 A2
*/

#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/timeb.h>

#include "P11.h"
#include "P12.h"

/*
The main function parses the data1.txt file and executes the brute force
inversion count as well as the merge sort inversion count. The main function also
prints the final inversion count and execution time for both methods.
*/
void printFunction(float num, int inversion);
int remainParse(int i, int array[]);

int main(int argc, char const *argv[])
{
	FILE *file;
	int array[50000] = {0};
	int array2[50000] = {0};
	char* firstString;
	int BFinversion = 0;
	int MSinversion = 0;
	char word[300];

	struct timeb timeStart;
	struct timeb timeEnd;
	struct timeb timeStart2;
	struct timeb timeEnd2;

	float BFtime;
	float MStime;

	int i = 0;
	//Error checking to ensure the correct syntax is used to run program
	if ((argc < 2) || (argc > 2))
	{
		printf("Incorrect input\nShould be ./part1 <data file for part 1>\n");
		return(-1);
	}

	file = fopen(argv[1], "r");
	while(!feof(file))
	{
		while (fgets(word, 300, file) != NULL)
		{
			firstString = strtok(word, " ");
			array[i] = atoi(firstString);
			i++;

			for(int x = 0; x < 4; x++)
			{
				array[i] = remainParse(i, array);
				i++;
			}
		}
	}
	fclose(file);

	int count = i;
	
	for(int z = 0; z < count; z++){
		array2[z] = array[z];
	}

	int* aSize = (int*)malloc(sizeof(int) * count); 
	//Execute Merge Sort Algorithm
	ftime(&timeStart2);
	MSinversion = mergeSort(array, aSize, 0, count- 1);
	ftime(&timeEnd2);

	MStime = (timeEnd2.millitm - timeStart2.millitm) + (timeEnd2.time - timeStart2.time)*1000;
	printf("\nMerge sort:\n");
	printFunction(MStime, MSinversion);	

	
	//Execute Brute Force Algorithm
	ftime(&timeStart);
	BFinversion = bruteforce(count, array2);
	ftime(&timeEnd);

	BFtime = (timeEnd.millitm - timeStart.millitm)+ (timeEnd.time - timeStart.time)*1000;
	printf("\nBrute Force:\n");
	printFunction(BFtime, BFinversion);
	
	return 0;
}

void printFunction(float num, int inversion)
{
	printf("Execution Time: %f mS\n",num);
	printf("Number of Inversions: %d\n", inversion);
}
//parse the remainder of the text file 
int remainParse(int i, int array[])
{
	char* String;
	String = strtok(NULL, " ");
	array[i] = atoi(String);
	return array[i];
}
