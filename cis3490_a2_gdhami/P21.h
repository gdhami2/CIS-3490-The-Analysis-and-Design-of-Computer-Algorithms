/*
Gurtej Dhami
0969863
CIS 3490 A2
*/
#ifndef __SKO01_P21__ 
#define __SKO01_P21__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <sys/timeb.h>

float gety(float m, float b, float x);
float getm(float a, float b, float c, float d);
float getb(float m, float y, float x);
int bruteforceConvex(int cnt,float arrx[],float arry[]);
void printFunc(int convex, float x[], float y[]);

#endif
