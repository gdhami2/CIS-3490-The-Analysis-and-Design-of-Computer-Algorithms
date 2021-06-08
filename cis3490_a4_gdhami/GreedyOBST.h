/*
Gurtej Dhami
0969863
03/29/2020
CIS 3490 Assignment 4
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct binNode Node;
struct binNode{
	char * word;
        float total;	
	float rec;
	Node * left;
	Node * right;
};

void GreedyOBST(FILE *file, char *userStr);

Node *createNode(char *word, float total, float rec);

Node *IntoTree(char * word, Node * root);

void destroyTree(Node * node);

void trav(int totalWords, Node *root);

int compare(const void *a, const void *b);

int hasC(Node* treeNode);

Node * scanTree(Node * root, char * word);

int getH(Node* treeNode);

Node * createGOBST(int i, int j);

int probIndex(int i, int j);
