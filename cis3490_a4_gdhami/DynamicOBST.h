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


typedef struct binTreeNode TreeNode;
struct binTreeNode{
	char * word;
        float total;	
	float rec;
	TreeNode * left;
	TreeNode * right;
};

void DynamicOBST(FILE *file, char *userStr);

TreeNode *createTreeNode(char *word, float total, float rec);

TreeNode *insertIntoTree(char * word, TreeNode * root);

void destroyTreeHelper(TreeNode * node);

void travel(int totalWords, TreeNode *root);

int compareWords(const void *a, const void *b);

int hasChild(TreeNode* treeNode);

TreeNode * searchTree(TreeNode * root, char * word);

int getHeight(TreeNode* treeNode);

TreeNode * createOBST(int i, int j);



