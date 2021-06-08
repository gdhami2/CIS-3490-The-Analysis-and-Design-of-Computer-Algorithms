/*
Gurtej Dhami
0969863
CIS 3490 A3
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <sys/timeb.h>

int preSort(FILE *file, long int userNumber);
void merge(long int array[],int l, int m, int r);
void mergeSort(long int arr[], int l, int r); 
