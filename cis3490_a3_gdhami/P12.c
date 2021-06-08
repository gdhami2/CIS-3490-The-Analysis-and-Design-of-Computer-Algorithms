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

#include "P12.h"
/*
P12 reads the user text file and executes a merge sort to put every text file number in descending order. These numbers are put into an array 
and merge sorted again to put the descending numbers in order of highest value to lowest value. The user number is merge sorted once and has each element put in descending order. Then a search occurs where all anagrams of the user number will be next to one another.
*/
int preSort(FILE *file, long int userNumber)
{
	struct timeb timeStart;
	struct timeb timeEnd;
	struct timeb timeStart2;
	struct timeb timeEnd2;
	float PSTime;
	float searchTime;
	int i = 0;
	int j = 0;
	long int k = 0;
	long int array[50000] = {0};
	long int arrayAsc[50000];
	char* firstString;
	char* secondString;
	char* thirdString;
	char* fourthString;
	char* fifthString;
	char word[300];
	long int cap;
	int totalDigits = 0;
	int store = 0;
	long int arraySplit[20];
	ftime(&timeStart);
	//every text file number is split into individual elements of an array to be mergesorted in descending order.
	//these numbers are then then converted back to a single integer number and put into an array
	while(!feof(file))
	{
		while (fgets(word, 300, file) != NULL && word[0] != '\n')
		{
			firstString = strtok(word, " ");
			array[i] = atoi(firstString);
			cap = array[i];
			totalDigits = 0;
			while(cap != 0){
				cap = cap/10;
				totalDigits++;
			}
			cap = array[i];
			store = 0;
			for(j = totalDigits-1; j >= 0; j--){
				store = cap % 10;
				arraySplit[j] = store;
				cap = cap/10;	 
			}
			mergeSort(arraySplit, 0, totalDigits-1);
			k = 0;
			for (j = 0; j < totalDigits; j++){
    				k = 10 * k + arraySplit[j];
			}
			arrayAsc[i] = k;
			i++;
			secondString = strtok(NULL, " ");
			array[i] = atoi(secondString);
			cap = array[i];
			totalDigits = 0;
			while(cap != 0){
				cap = cap/10;
				totalDigits++;
			}
			cap = array[i];
			store = 0;
			for(j = totalDigits-1; j >= 0; j--){
				store = cap % 10;
				arraySplit[j] = store;
				cap = cap/10;	 
			}
			mergeSort(arraySplit, 0, totalDigits-1);
			k = 0;
			for (j = 0; j < totalDigits; j++){
    				k = 10 * k + arraySplit[j];
			}
			arrayAsc[i] = k;
			i++;

			thirdString = strtok(NULL, " ");
			array[i] = atoi(thirdString);
			cap = array[i];
			totalDigits = 0;
			while(cap != 0){
				cap = cap/10;
				totalDigits++;
			}
			cap = array[i];
			store = 0;
			for(j = totalDigits-1; j >= 0; j--){
				store = cap % 10;
				arraySplit[j] = store;
				cap = cap/10;	 
			}
			mergeSort(arraySplit, 0, totalDigits-1);
			k = 0;
			for (j = 0; j < totalDigits; j++){
    				k = 10 * k + arraySplit[j];
			}
			arrayAsc[i] = k;
			i++;

			fourthString = strtok(NULL, " ");
			array[i] = atoi(fourthString);
			cap = array[i];
			totalDigits = 0;
			while(cap != 0){
				cap = cap/10;
				totalDigits++;
			}
			cap = array[i];
			store = 0;
			for(j = totalDigits-1; j >= 0; j--){
				store = cap % 10;
				arraySplit[j] = store;
				cap = cap/10;	 
			}
			mergeSort(arraySplit, 0, totalDigits-1);
		
			k = 0;
			for (j = 0; j < totalDigits; j++){
    				k = 10 * k + arraySplit[j];
			}
			arrayAsc[i] = k;
			i++;

			fifthString = strtok(NULL, " ");
			array[i] = atoi(fifthString);
			cap = array[i];
			totalDigits = 0;
			while(cap != 0){
				cap = cap/10;
				totalDigits++;
			}
			cap = array[i];
			store = 0;
			for(j = totalDigits-1; j >= 0; j--){
				store = cap % 10;
				arraySplit[j] = store;
				cap = cap/10;	 
			}
			
			mergeSort(arraySplit, 0, totalDigits-1);
			k = 0;
			for (j = 0; j < totalDigits; j++){
    				k = 10 * k + arraySplit[j];
			}
			arrayAsc[i] = k;
			i++;
		}
	}
	int num = i;
	//the array containing every mergesorted text file number is mergesorted again to have each element in order of descending value
	mergeSort(arrayAsc,0, num-1);
	ftime(&timeEnd);
	PSTime = (timeEnd.millitm - timeStart.millitm) + (timeEnd.time - timeStart.time)*1000;
	ftime(&timeStart2);
	int z = 0;
	int totAnagram = 0;	
	long int UserN = userNumber;
	totalDigits = 0;
	long int userNumasArr[20];
	//the user number is split and mergesorted into descending order and made whole again  
	while(UserN != 0){
		UserN = UserN/10;
		totalDigits++;
	}
	UserN = userNumber;
	store = 0;
	for(i = totalDigits-1; i >= 0; i--){
		store = UserN % 10;
		userNumasArr[i] = store;
		UserN = UserN/10;	 
	}
	mergeSort(userNumasArr, 0, totalDigits-1);
	k = 0;
	for (j = 0; j < totalDigits; j++){
    		k = 10 * k + userNumasArr[j];
	}
	z=0;
	//the user number is compared with each number of the array containing the text file numbers and stops once the anagrams that are next
	// to each other are found
	while(arrayAsc[z] >= k){
		if(k == arrayAsc[z]){
			totAnagram++;
		}
		z++;
	}
	ftime(&timeEnd2);
	searchTime = (timeEnd2.millitm - timeStart2.millitm) + (timeEnd2.time - timeStart2.time)*1000;
	printf("Pre Sort Time: %f mS\n",PSTime);
	printf("Search Time: %f mS\n",searchTime);
	return totAnagram;
}
//merge function implemented to create a descending array
void merge(long int arr[],int l, int m, int r) 
{  
	int i;
	int j;
	int k; 
	int num1; 
	int num2; 
	num1 = m - l + 1;
	num2 =  r - m;
  
	long int Left[num1]; 
	long int Right[num2];
  
	for (j = 0; j < num2; j++){ 
	        Right[j] = arr[m + 1+ j]; 
  	}
	for (i = 0; i < num1; i++){ 
	        Left[i] = arr[l + i];
	} 
	i = 0; 
	j = 0;  
	k = l;  
	while (j < num2 && i < num1){ 
        	if (Left[i] >= Right[j]){ 
            		arr[k] = Left[i]; 
            		i++; 
        	} 
        	else{ 
            		arr[k] = Right[j]; 
            		j++; 
        	} 
        	k++; 
	} 
	while (j < num2){ 
	        arr[k] = Right[j]; 
	        k++; 
		j++;
	} 
  
	while (i < num1){ 
        	arr[k] = Left[i];
		k++; 
        	i++;  
	} 

}  

void mergeSort(long int arr[], int l, int r) 
{ 
	if (l < r){ 
  
   	     int m = l+(r-l)/2; 
  
        	mergeSort(arr, l, m); 
        	mergeSort(arr, m+1, r); 
  
        	merge(arr, l, m, r); 
	} 
}  
