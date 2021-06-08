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
#include "P22.h"

/*
P22 takes in the user text file and the user string and creates a shift table based on the users input pattern. The table that's created 
is indexed with the alphebets characters and is filled with shift sizes. The pattern is alligned with the start of the current text file line 
and the last element followed by the every element in the pattern beforehand are compared to the current word in the text file. If all
elements line up as a match then a matching string has been found and the string counter is incremented. If a mismatching pair is encountered 
then the table value of the character index is retrieved from the shift table where the specific index is the character alligned with the 
last element of the user pattern. The amount of string matches along with the number of shifts and run time are printed here. 
*/
void horspoolString(FILE *file, char *userStr){

	userStr[strlen(userStr)] = '\0';
	int lengthUsrStr = strlen(userStr);
	char word[520];
	char Table[200];
	struct timeb timeStart;
	struct timeb timeEnd;
	float HStime;
	int lengthFileWord = 0;
	int i = 0;
	int j = 0;
	int arr[2];
	arr[0] = 0;
	arr[1] = 0;
	//creation of shift table
	for(i = 0; i < 200; i++){
		Table[i] = lengthUsrStr;
	}
	for(j = 0; j < lengthUsrStr-1; j++){
		Table[(int)userStr[j]] = lengthUsrStr - 1 - j;
	}
	ftime(&timeStart);
	while(!feof(file))
	{
		while (fgets(word, 520, file) != NULL && word[0] != '\n'){
			word[strlen(word)] = '\0';
			lengthFileWord = strlen(word);
			//check for multivalue character elements that will cause issues for the shift table 
			for(i = 0; i < lengthFileWord; i++){
				if((int)word[i] < 0){
					word[i] = ' ';
				}
			}
			ShiftTable(userStr, word, lengthFileWord, lengthUsrStr,Table, arr);
		}
	}
	ftime(&timeEnd);
	HStime = (timeEnd.millitm - timeStart.millitm)+ (timeEnd.time - timeStart.time)*1000;
	printf("\nHorspool Algorithm:\n");
	printf("Number of shifts: %d\n", arr[1]);
	printf("Execution Time: %f mS\n",HStime);
	printf("Number of string matches: %d\n", arr[0]);	
}

void ShiftTable(char *userStr, char *word,int lengthFileWord, int lengthUsrStr,char *Table, int arr[]){
	int k = 0;
	int i = 0;
	int same = 0;
	int shifts = 0;
	i = lengthUsrStr - 1;
	while(i < lengthFileWord){
		k = 0;
		while(k < lengthUsrStr && userStr[lengthUsrStr - 1 - k] == word[i-k]){
			k++;
		}
		if(k == lengthUsrStr){
			same++;
			shifts++;
			i = i + Table[(int)word[i]];
		}
		else{
			shifts++;
			i = i + Table[(int)word[i]];
		}
	}
	arr[0] += same;
	arr[1] += shifts;
}
