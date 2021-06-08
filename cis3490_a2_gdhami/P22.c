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

#include "P22.h"
/*
P22 is a recursive implementation of the convex hull algorithm for a given array of x and y coordinates. 
Once a line has been calculated for the minimum and maximum x coordinates the convex hull points can be found on either side of the line recursively. From here the point with the maximum distance from the line is found. If no such coordinate exists then the coordinates of the line are stored and the convex variable is incremented. If a coordinate is found with the max distance from the line then a new line is made with these points and we must reccur for the two parts divided by this new line. The coordinates of the convex hull points are printed in increasing order of x value. The convex coordinate number is returned back to main.
*/

struct Hull{
	float x[30000];
	float y[30000];
};

int recHull(int count, float arrayx[],float arrayy[])
{
	if(count < 3){
		printf("Error hull needs atleast 3 points");
		return 0;
	}
	//finding points with minimum and maximum x coordinate
	int min_x, max_x = 0;
	
	for(int i = 1; i < count; i++){
		if(arrayx[i] < arrayx[min_x]){
			min_x = i;
		}
		if(arrayx[i] > arrayx[max_x]){
			max_x = i;
		}
	}
	//recursively find convex hull points on one side of line joining a[min_x] and a[max_x]
	quickHull(arrayx, arrayy, count, arrayx[min_x], arrayy[min_x], arrayx[max_x], arrayy[max_x], 1);

	quickHull(arrayx, arrayy, count, arrayx[min_x], arrayy[min_x], arrayx[max_x], arrayy[max_x], -1);
	//Indicates the end of the convex hull coordinates and begins the printing process 
	return countfunc(0);
}
//endpoints of line line are min_x and max_x
//side has value 1 or -1 depending on side of line
void quickHull(float arrayx[], float arrayY[], int count, float xmin_x, float ymin_x, float xmax_x, float ymax_x, int side)
{
	static struct Hull h;
	int indicate = -1;
	int max_dist = 0;
	static int convex = 0;
	//finding the point with max distance from line on the specific side of line
	for(int i = 0; i < count; i++){
		float temp = Dist(xmin_x, ymin_x, xmax_x, ymax_x, arrayx[i], arrayY[i]);
		if(lineSide(xmin_x, ymin_x, xmax_x, ymax_x, arrayx[i], arrayY[i]) == side && temp > max_dist){
			indicate = i;
			max_dist = temp;
		}
		
	}
	//if no point is found add the endpoints of line to the convex hull
	if(indicate == -1){
		if(convex == 0){
		}
		int checkMin = 0;
		int checkMax = 0;
		//check to see if point is already stored
		for(int j = 0; j < convex; j++){
			if(h.x[j] == xmin_x && h.y[j] == ymin_x){
				checkMin = 1;
			}
			if(h.x[j] == xmax_x && h.y[j] == ymax_x){
				checkMax = 1;
			}
		}
		//if not already stored then store and increment convex
		if(checkMin == 0){
			h.x[convex] = xmin_x;
			h.y[convex] = ymin_x;
			convex++;
			storetoIncr(xmin_x, ymin_x, convex);
			countfunc(convex);
		}
		//if not already stored then store and increment convex
		if(checkMax == 0){
			h.x[convex] = xmax_x;
			h.y[convex] = ymax_x;
			convex++;
			storetoIncr(xmax_x, ymax_x, convex);
			countfunc(convex);
		}
			return;
	} 

	
	//reccur for two parts divided by arrayx[ind] 
	quickHull(arrayx,arrayY, count, arrayx[indicate], arrayY[indicate], xmin_x, ymin_x, -lineSide(arrayx[indicate], arrayY[indicate], xmin_x, ymin_x, xmax_x, ymax_x));
	quickHull(arrayx,arrayY, count, arrayx[indicate], arrayY[indicate], xmax_x, ymax_x, -lineSide(arrayx[indicate], arrayY[indicate], xmax_x, ymax_x, xmin_x, ymin_x));

	countfunc(convex);
}

void storetoIncr(float x, float y, int convex){
	static struct Hull h;
	static int count = 0;
	float xIncr;
	float yIncr;
	//The only time convex will equal zero is when it is when the end of the algorithm is triggered and 		convex is set to zero in a function call in storetoIncr()
	if(convex == 0){
		for(int z = 0; z < count; z++){
			for(int n = 0; n < count; n++){
				if(z != n){
					//put coordinates in incrementing order of x value
					if(((h.y[z] < h.y[n]) && (h.x[z] == h.x[n])) || (h.x[z] < h.x[n])){
						//swap z and n for x
						xIncr = h.x[z];
						h.x[z] = h.x[n];
						h.x[n] = xIncr;
						//swap z and n for y
						yIncr = h.y[z];
						h.y[z] = h.y[n];
						h.y[n] = yIncr;
					}
				}
			}
		}
		printf("The convex hull set is made up of: \n");
		for (int i = 0; i < count; i++) {
		printf("%7.1f, %7.1f\n", h.x[i], h.y[i]);
	}
	}
	h.x[count] = x;
	h.y[count] = y;
	count = convex;
	
}
int countfunc(int convex)
{
	static int count = 0;
	float dummyx = 0;
	float dummy = 0;
	//This condition is only met when all convex coordinates have been found
	if(convex == 0){
		//This activates the print sequence for storetoIncr()
		//Otherwise this function only stores each convex hull coordinate
		storetoIncr(dummyx,dummy, 0);
		//returns the current convex number to recHull which is then to be returned to main where it 			will be printed 
		return count;
	}
	else{
		//store the current convex number
		count = convex;
		return count;
	}
}


float Dist(float xmin_x, float ymin_x, float xmax_x, float ymax_x, float px, float py)
{
	return abs((py - ymin_x) * (xmax_x - xmin_x) - (ymax_x - ymin_x) * (px - xmin_x));
}

float lineSide(float xmin_x, float ymin_x, float xmax_x, float ymax_x, float px, float py)
{
	float val = ((py - ymin_x) * (xmax_x - xmin_x) - (ymax_x - ymin_x) * (px - xmin_x));
	if(val > 0){
		return 1;
	}
	if(val < 0){
		return -1;
	}
	return 0;
}
