/*
Gurtej Dhami
0969863
CIS 3490 A2
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <sys/timeb.h>

#include "P21.h"

/*
P21 is a brute force implementation of the convex hull algorithm for a given array of x and y coordinates. 
Once a line has been calculated for the two coordinates the location of every other point relative to this line must be found. If all are on one of the sides then these coordinates are stored. The coordinates that make up the convex hull are printed in increasing order of x value. The amount of convex hull coordinates are returned. 
*/

struct Coordinates{
	float x[30000];
	float y[30000];
};

float getLine(float m, float b, float x)
{
	return (m*x) + b;
}

float getm(float a, float b, float c, float d){
	return(a - b)/(c - d);
}

float getb(float m, float y, float x)
{
	return y - (m*x);
}


int bruteforceConvex(int cnt,float arrx[],float arry[])
{
	int gThan = 0;
	int lThan = 0;
	float xIncr;
	float yIncr;
	int convex = 0;
	struct Coordinates c;

	for (int i = 0; i < cnt; i++)
	{
		for (int j = 0; j < cnt; j++)
		{
			
			if (arrx[j] != arrx[i])
			{

				float m = getm(arry[i], arry[j], arrx[i], arrx[j]);
				float b = getb(m, arry[i], arrx[i]);
				
				//checks other elements to see on which side of the line they are 
				for(int k = 0; k < cnt; k++) {
					if (k != i && k != j) {
						float Line = getLine(m, b, arrx[k]);
						if (arry[k] < Line) {
							lThan = 1;
							
						}
						else if (arry[k] > Line) {
							gThan = 1;
						}
					}
				}
				
				
			}

			else{
				for (int k = 0; k < cnt; k++)
				{
					if ((k != i) && (k != j))
					{
						if (arrx[i] < arrx[k])
						{
							gThan = 1;
						}

						else if (arrx[i] > arrx[k])
						{
							lThan = 1;
						}


					}
				}
			}
			
			
			if (gThan != lThan) {
				//checks if coordinates are in array if not then put in struct and increase 					convex count				
				int check1 = 0;
				for(int z = 0; z < convex + 1; z++){

					if(arry[j] == c.y[z] && arrx[j] == c.x[z]){
						check1 = 1;
					}
				}
				if (check1 == 0) {
					c.x[convex] = arrx[j];
					c.y[convex] = arry[j];
					convex++;
				}
				//checks if coordinates are in array if not then put in struct and increase 					convex count
				int check2 = 0;
				for(int z = 0; z < convex + 1; z++){

					if(arry[i] == c.y[z] && arrx[i] == c.x[z]){
						check2 = 1;
					}				
				}

				if (check2 == 0) {
					c.x[convex] = arrx[i];
					c.y[convex] = arry[i];
					convex++;
				}

			}
			gThan = 0;
			lThan = 0;
		}
	}

	//put the coordinates in order of increasing x value
	for(int z = 0; z < convex; z++){
		for(int n = 0; n < convex; n++){
			if(z != n){
				if(((c.y[z] < c.y[n]) && (c.x[z] == c.x[n])) || (c.x[z] < c.x[n])){
					//swap z and n for x
					xIncr = c.x[z];
					c.x[z] = c.x[n];
					c.x[n] = xIncr;
					//swap z and n for y
					yIncr = c.y[z];
					c.y[z] = c.y[n];
					c.y[n] = yIncr;
				}
			}
		}
	}
	printFunc(convex, c.x, c.y);
			
	return convex;
}

void printFunc(int convex, float x[], float y[]){
	printf("The convex hull set is made up of: \n");
	for (int i = 0; i < convex; i++) {
		printf("%7.1f, %7.1f\n", x[i], y[i]);
	}
}
