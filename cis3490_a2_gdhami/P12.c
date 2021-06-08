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
#include "P12.h"

struct Inversion{
	int inversion;
};
  
/*
P12 uses a recursion to split the array into two left and right parts. These two subarrays are then sorted into
ascending order and merged back together. The inversion count that is returned is the summation of the inversion count in the left subarray, right subarray and the inversions in merging.  
*/
int merge(int l, int m, int r, int array[], int aSize[]) 
{  
	//index for left subarray
	int x = l;
	//index for the right subarray
	int y = m + 1;
	//index for merged subarray
	int z = l; 

	struct Inversion I;
	I.inversion = 0;
  


	while ((y <= r)&&(x <= m)) { 
		if (array[x] > array[y]) { 
								
			aSize[z++] = array[y++]; 
  
            	
            		I.inversion = I.inversion + (m + 1 - x);
        	} 
        	else{ 
            		aSize[z++] = array[x++];  
        	} 
	} 
  
   //remaining elements of the right subarray are copied
	while (y <= r){
        	aSize[z++] = array[y++];
	}
    //remaining elements of the left subarray are copied
	while (x <= m){
		aSize[z++] = array[x++];
  	}
    //the merged elemets are copied to the original array.
	for (x = l; x <= r; x++){ 
		array[x] = aSize[x]; 
	}
		

    return I.inversion; 
}  

int mergeSort(int array[], int aSize[], int l, int h) 
{ 
	int mid = 0;
	struct Inversion In;
	In.inversion = 0;
	if (h > l) 
	{ 
        //Divide the array into two parts
		mid = (h + l) / 2; 
  
        //inversion of left part
	        In.inversion = In.inversion + mergeSort(array, aSize, l, mid);
	//inversion of right part 
	        In.inversion = In.inversion + mergeSort(array, aSize, mid + 1, h); 
  
        //merging of both subarrays
	        In.inversion = In.inversion + merge(l, mid, h, array, aSize); 
	} 
	return In.inversion; 
} 

