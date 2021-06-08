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
/*
P11 takes two elements in an array by the use of two for loops
and compares if the value at index "i" is greater then that of index "j". 
If this condition is met the inversion count increases by one until it is ultimately returned.
*/
int bruteforce(int count, int array[])
{
	int inversion = 0;	
	for(int i = 0; i < count; i++)
	{
		for (int j = i+1; j < count; j++)
		{
			if (array[i] > array[j])
			{
				inversion = inversion +1;
			}
		}
	}
	return inversion;

}

