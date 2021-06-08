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

#include "P11.h"
/*
P11 reads the user text file and user number and compares the number of occurences for each number between 0 and 9
for the user number and every element in the text file. If an element in the text file and the user number contain the exact
amount of each number then the anagram count in incremented and is printed.
*/
int bruteforce(FILE *file, long int userNumber)
{
	int i = 0;
	long int array[50000] = {0};
	char* firstString;
	char word[300];

	while(!feof(file))
	{
		while (fgets(word, 300, file) != NULL && word[0] != '\n')
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

	int count = i;

	printf("\n");
	printf("The anagrams are:\n");
	int totAnagram = 0;	
	long int UserN = userNumber;
	int totalDigits = 0;
	int zero,one,two,three,four,five,six,seven,eight,nine;
	long int userNumasArr[25];
	//find number of digits in the user number
	while(UserN != 0){
		UserN = UserN/10;
		totalDigits++;
	}
	UserN = userNumber;
	int store = 0;
	//store each number as its own element in an array
	for(i = totalDigits-1; i >= 0; i--){
		store = UserN % 10;
		userNumasArr[i] = store;
		UserN = UserN/10;	 
	}
	int num = 0;
	zero=one=two=three=four=five=six=seven=eight=nine = 0;
	//use the user number array to determine the amount of each number that the user has entered
	for(i = 0; i < totalDigits; i++){
		num = userNumasArr[i];
		switch(num){
			case 0:
				zero++;
			break;
			case 1:
				one++;
			break;
			case 2:
				two++;
			break;
			case 3:
				three++;
			break;
			case 4:
				four++;
			break;
			case 5:
				five++;
			break;
			case 6:
				six++;
			break;
			case 7:
				seven++;
			break;
			case 8:
				eight++;
			break;
			case 9:
				nine++;
			break;
		}
	}
	int incr = 0;	
	long int holdTamper = 0;
	int numberLen = 0;
	int zeroN,oneN,twoN,threeN,fourN,fiveN,sixN,sevenN,eightN,nineN;
	long int arraySplit[25];
	while(incr != count){
		holdTamper = array[incr];
		numberLen = 0;
		//find number of digits in the text file number
		while(holdTamper != 0){
			holdTamper = holdTamper/10;
			numberLen++;
		}
			holdTamper = array[incr];
			store = 0;
			//store each number as its own element in an array
			for(i = numberLen-1; i >= 0; i--){
				store = holdTamper % 10;
				arraySplit[i] = store;
				holdTamper = holdTamper/10;	 
			}
			num = 0;
			zeroN=oneN=twoN=threeN=fourN=fiveN=sixN=sevenN=eightN=nineN = 0;
			//use the text file number array to determine the amount of each number for the current text file number
			for(i = 0; i < numberLen; i++){
				num = arraySplit[i];
				switch(num){
					case 0:
						zeroN++;
					break;
					case 1:
						oneN++;
					break;
					case 2:
						twoN++;
					break;
					case 3:
						threeN++;
					break;
					case 4:
						fourN++;
					break;
					case 5:
						fiveN++;
					break;
					case 6:
						sixN++;
					break;
					case 7:
						sevenN++;
					break;
					case 8:
						eightN++;
					break;	
					case 9:
						nineN++;
					break;
				}
			}
			//the current text file number is printed and the anagram counter increments if it is an anagram of the user number
			if(zero == zeroN && one == oneN && two == twoN && three == threeN && four == fourN && five == fiveN && six == sixN && seven == sevenN && eight == eightN && nine == nineN){
				printf("%ld\n", array[incr]);
				totAnagram++;
			}
		incr++;
	}
	return totAnagram;
}
//parse the remainder of the text file 
int remainParse(int i, long int array[])
{
	char* String;
	String = strtok(NULL, " ");
	array[i] = atoi(String);
	return array[i];
}
