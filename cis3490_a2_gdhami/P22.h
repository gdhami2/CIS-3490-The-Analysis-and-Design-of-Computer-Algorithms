/*
Gurtej Dhami
0969863
CIS 3490 A2
*/
#ifndef __SKO01_P22__ 
#define __SKO01_P21__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <sys/timeb.h>

int recHull(int count, float arrayx[],float arrayy[]);

void quickHull(float arrayx[], float arrayY[], int count, float xmin_x, float ymin_x, float xmax_x, float ymax_x, int side);

int countfunc(int convex);
void storetoIncr(float x, float y, int convex);

float Dist(float xmin_x, float ymin_x, float xmax_x, float ymax_x, float px, float py);
float lineSide(float xmin_x, float ymin_x, float xmax_x, float ymax_x, float px, float py);

#endif
