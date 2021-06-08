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

#include "P21.h"
#include "P22.h"

/*
The main2 file parses the data2.txt file and executes the brute force
convex hull algorithm as well as the quick hull algorithm. The main function also
prints the final amount of points that make up the convex hull as well as the execution time for both methods.
*/

int main(int argc, char const *argv[])
{
	FILE *file;
	char *convexFirst;
	char *convexSecond;
	char word[300];
	float arrayX[30000] = {0};
	float arrayY[30000] = {0};

	int convex = 0;
	int convex2 = 0;

	struct timeb timeStart;
	struct timeb timeEnd;
	struct timeb timeStart2;
	struct timeb timeEnd2;
	int i = 0;
	float BFtime;
	float MStime;
	//Error checking to ensure the correct syntax is used to run program
	if ((argc < 2) || (argc > 2))
	{
		printf("Incorrect input\nShould be ./part2 <data file for part 2>\n");
		return(-1);
	}

	file = fopen(argv[1], "r");
	i = 0;
	while(!feof(file))
	{
		while (fgets(word, 300, file) != NULL)
		{
			convexFirst = strtok(word, " ");
			arrayX[i] = atof(convexFirst);
			convexSecond = strtok(NULL, " ");
			arrayY[i] = atof(convexSecond);
			i++;

		}
	}
	fclose(file);
	int count = i;
	//Execution of quick hull
	ftime(&timeStart2);
	convex2 = recHull(count, arrayX, arrayY);
	ftime(&timeEnd2);

	MStime = (timeEnd2.millitm - timeStart2.millitm) + (timeEnd2.time - timeStart2.time)*1000;

	printf("\nQuick Hull\nExecution Time:%fmS. Convex points: %d\n",MStime, convex2);	
	//Execution of brute force convex hull
	ftime(&timeStart);
	convex = bruteforceConvex(count, arrayX, arrayY);
	ftime(&timeEnd);
	

	BFtime = (timeEnd.millitm - timeStart.millitm)+ (timeEnd.time - timeStart.time)*1000;
	printf("\nBrute Force\nExecution Time:%fmS. Convex Count:%d\n",BFtime, convex);


}

