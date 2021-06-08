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
/*
P21 takes in the user file and the user string to be searched. The length of the user string and the current line of the text file are found.
The user string starts at the beginning of a line and shifts one index after each character has been compared. If the index of compared letters
is equal to the length of the current word then a match has been found and the string comparison counter will increment. The function returns
the number of comparisons at the end and prints the number of shifts here.
*/
int bruteforceString(FILE *file, char *userStr){
	
	userStr[strlen(userStr)] = '\0';
	char word[520];
	int sameStr = 0;
	int k = 0;
	int lengthFileWord = 0;
	int lengthUsrStr = 0;
	int i = 0;
	int check = 0;
	int shifts = 0;
	while(!feof(file))
	{
		while (fgets(word, 520, file) != NULL && word[0] != '\n'){
			lengthFileWord = strlen(word);	
			lengthUsrStr = strlen(userStr);
			word[strlen(word)] = '\0';
			for(k = 0; k < lengthFileWord - lengthUsrStr; k++){
				shifts++;
				check = 0;
				for(i = 0; i < lengthUsrStr; i++){
					if(word[k + i] == userStr[i]){
						check++;
					}
					else{
						break;
					}
				}
				if(check == lengthUsrStr){
					sameStr++;
				}
			}
		}
	}
	printf("Number of shifts: %d\n", shifts);
	return sameStr;	
}
