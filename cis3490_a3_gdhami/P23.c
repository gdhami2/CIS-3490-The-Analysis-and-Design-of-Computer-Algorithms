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
#include "P23.h"
/*
P23 takes in the user text file and the user string and creates a bad char table based on the users input pattern.The pattern is alligned with the start of the current text file line and the last element followed by the every element in the pattern beforehand are compared to the current word in the text file. If all elements line up as a match then a matching string has been found and the string counter is incremented. If a mismatching pair is encountered then the table value of the character index is retrieved from the bad char table where the specific index is the character in the text alligned with mismatching user pattern. The corresponding good suffix is retreived and the shift is executed 
based on the maximum of two avalible shifts. The amount of string matches along with the number of shifts and run time are printed here. 
*/
void boyermooreString(FILE *file, char *userStr){

	userStr[strlen(userStr)] = '\0';
	int lengthUsrStr = strlen(userStr);
	char word[520];
	int badchar[200];
	int arr[2];
	arr[0] = 0;
	arr[1] = 0;
	struct timeb timeStart;
	struct timeb timeEnd;
	float BMtime;
	int lengthFileWord = 0;
	int i = 0;
	//construction of bad char table
	for(i = 0; i < 200; i++){
		badchar[i] = -1;
	}
	for(i = 0; i < lengthUsrStr; i++){
		badchar[(int)userStr[i]] = i;
	}
	ftime(&timeStart);
	while(!feof(file))
	{
		while (fgets(word, 520, file) != NULL && word[0] != '\n'){
			word[strlen(word)] = '\0';
			lengthFileWord = strlen(word);
			//check for multivalue character elements that will cause issues for table
			for(i = 0; i < lengthFileWord; i++){
				if((int)word[i] < 0){
					word[i] = ' ';
				}
			}
			shifts(userStr, word,badchar,lengthUsrStr, lengthFileWord, arr);
			
		}
	}
	ftime(&timeEnd);
	BMtime = (timeEnd.millitm - timeStart.millitm)+ (timeEnd.time - timeStart.time)*1000;
	printf("\nBoyer Moore Algorithm:\n");
	printf("Number of shifts: %d\n", arr[1]);
	printf("Execution Time: %f mS\n",BMtime);
	printf("Number of string matches: %d\n", arr[0]);	
}

void shifts(char *userStr, char *word, int badchar[], int lengthUsrStr, int lengthFileWord, int arr[]){
	int k = 0;
	int j = 0;
	int same = 0;
	int shifts = 0;
	int ind = 0;
	while(k <= (lengthFileWord - lengthUsrStr)){
		j = lengthUsrStr - 1;

		while(userStr[j] == word[k + j] && j >= 0){
			j--;
		}
		if(j >= 0){
			ind = (int)word[k + j];
			if(1 > j - badchar[ind]){
				shifts++;
				k = k + 1;
			}
			else{
				shifts++;
				k = k + j - badchar[ind];
			}
		}
		else{
			same++;
			if(k + lengthUsrStr > lengthFileWord){
				shifts++;
				k = 1;
			}
			else{
				shifts++;
				ind = (int)word[lengthUsrStr + k];
				k = k + lengthUsrStr - badchar[ind];
			}
		}
	}
	arr[0] += same;
	arr[1] += shifts;
}
