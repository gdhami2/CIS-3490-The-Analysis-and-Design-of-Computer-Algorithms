/*
Gurtej Dhami
0969863
03/29/2020
CIS 3490 Assignment 4
*/
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "DynamicOBST.h"

float C[2000][2000];
int R[2000][2000];
double P[2000];
char *Keys[2000];
int index = 1;

/*
DynamicOBST takes in the user file and the user string to scan the dynamic optimal binary search tree with. The words in the text file are sorted in order and the main table and root table are calculated within the function. Once the Dynamic Optimal Binary Search Tree has been created the search function scans and compares each node with the users input string until the correct node is found. Every comparison results in the function displaying the minimum average number of comparisons of the subtree to the terminal. 
*/
void DynamicOBST(FILE *file, char *userStr){
	userStr[strlen(userStr)] = '\0';
	TreeNode *root = NULL;
	TreeNode *Randroot = NULL;
	char word[520];
	int lengthFileWord = 0;
	int i = 0;
	int numChar = 0;
	char realWord[50];
	int totalWords = 0;
	//obtain each sentence from the text file and put the words into tree
	while(!feof(file))
	{
		while (fgets(word, 520, file) != NULL && word[0] != '\n'){
			word[strlen(word)] = '\0';
			lengthFileWord = strlen(word);
			for(i = 0; i < lengthFileWord; i++){
				if(word[i] != ' ' && word[i] != '\0' && word[i] != '\n' && word[i] != '\t' && word[i] != '\r'){
					realWord[numChar] = word[i];
					numChar++;
				}
				else{
					if(numChar > 0){
						realWord[numChar] = '\0';
						root = insertIntoTree(realWord, root);
						numChar = 0;
						totalWords++;
					}
				}
			}
		}
	}
	fclose(file);
	Randroot = root;
	travel(totalWords, Randroot);
	int n = index;
	int j = 0;
	double minval = 0;
	int k = 0;
	int Kmin = 0;
	double sum = 0;
	int s = 0;
	int d = 0;
	for(i = 1; i <= n; i++){
		C[i][i-1] = 0;
		C[i][i] = P[i];
		R[i][i] = i;	
	}
	C[n+1][n] = 0;
	
	for(d = 1; d < n; d++){
		for(i = 1; i <= n-d; i++){
			j = i+d;
			minval = 99999999;
			for(k = i; k <= j; k++){
				if((C[i][k-1] + C[k+1][j]) < minval){
					minval = C[i][k-1]+C[k+1][j];
					Kmin = k;
				}
			}
			R[i][j] = Kmin;
			sum = P[i]; 
			for(s = i+1; s <= j; s++){
				sum = sum + P[s];
			}
			C[i][j] = minval + sum;
		}
	}
	int z = index-1;
	TreeNode *optBST = createOBST(1, z);
	searchTree(optBST, userStr);
	destroyTreeHelper(root);
	destroyTreeHelper(optBST);
	
	
}
//a tree node is created when given the word field the total field and the number of recurrences as a field
//the new tree node is returned
TreeNode *createTreeNode(char *word, float total, float rec){
	TreeNode * treenode = (TreeNode*)malloc(sizeof(TreeNode));
	char *nWord = malloc(sizeof(char)*(strlen(word)+1));
	strcpy(nWord, word);
	treenode->total = total;
	treenode->rec = rec;
	treenode->word = nWord;
	treenode->right = NULL;
	treenode->left = NULL;
	return treenode;
}

//the memory for each node is free'd one at a time recursively
void destroyTreeHelper(TreeNode * node){
	int numChildren = hasChild(node);
	int nodeHeight = getHeight(node);
	if ( numChildren == 0 && nodeHeight == 1 ) { 
		return; 
	}
	if(node->right != NULL && numChildren == 1 && nodeHeight != 1){
		destroyTreeHelper(node->right);
	}
	if(node->left != NULL && numChildren == 1 && nodeHeight != 1){
		destroyTreeHelper(node->left);
	}
	free(node->word);
	free(node);
}
//obtain the height of the current node relative to the tree
int getHeight(TreeNode* treeNode){
	if(treeNode == NULL){
        	return 0;
	}

	int leftHeight = getHeight(treeNode->left) + 1;
	int rightHeight = getHeight(treeNode->right) + 1;

	if(leftHeight > rightHeight){
		return leftHeight;
	}
	else{
	        return rightHeight;
	}
}
//the current node is checked to see if it has children and it is not a leaf
//first the left subtree is traversed and then the right recursively
//the keywords are sorted into Words[] and the the words probability is put into Prob[]
//if the current node is a leaf the function returns
void travel(int totalWords, TreeNode *root){
	int numChildren = hasChild(root);
	int nodeHeight = getHeight(root);
	if(root->left != NULL && numChildren == 1 && nodeHeight != 1){
		travel(totalWords, root->left);
	}
	Keys[index] = root->word;
  	P[index] = (float)root->rec/totalWords;
    	index++;
	if(root->right != NULL && numChildren == 1 && nodeHeight != 1){
		travel(totalWords, root->right);
	}
	if(numChildren == 0 && nodeHeight == 1){
	        return;
	}
}
//search the greedy optimal binary search tree for the user word
//print each word that is compared along with its probability 
//the direction of the next subtree is also printed
TreeNode * searchTree(TreeNode * root, char * word) {
	if (hasChild(root) != 0){
		if (compareWords(word, root->word) == 0) {
		// same: update the fequency of the word given
		printf("Compared with %s (%.2f), found.\n", root->word, root->total);
		} 
		else if (compareWords(word, root->word) == 1) {
			// go right
			printf("Compared with %s (%.2f), go right subtree.\n", root->word, root->total);
			root->right = searchTree(root->right, word);
		} 
		else {
			// go left
			printf("Compared with %s (%.2f), go left subtree.\n", root->word, root->total);
			root->left = searchTree(root->left, word);
		}
	} 
	else {
	    printf("not found!\n");
	}
	return root;
}
//a recursive function to create a dynamic optimal binary search tree
//the i and j index define the root value which causes a split for a left and right subtree
//the word and the root value associated with this index is the split for a new left and right subtree
//this continues recursively
//the dynamic optimal binary search tree is returned
TreeNode * createOBST(int i, int j){
	TreeNode * newNode;
	if(i <= j){
		// find the root
		char *newWord = Keys[R[i][j]];
		newNode = createTreeNode(newWord,C[i][j],1);
		newNode->left = createOBST(i, R[i][j]-1); 
		newNode->right = createOBST(R[i][j]+1, j);
	}
	else{
    		newNode = NULL;
	}
	return newNode;
}
//take the current root and create a node if it is a leaf
//sort the words in either the left subtree, right subtree or the word is a copy and thus increment the recurrence variable in the struct
//the root node is returned 
TreeNode *insertIntoTree(char * word, TreeNode * root){
	int numChildren = hasChild(root);
	int nodeHeight = getHeight(root);
	if (numChildren == 0 && nodeHeight == 0) { 
		TreeNode* temp = createTreeNode(word,1,1);
        	return temp; 
	}
	int compare = 0;
	compare = compareWords(word, root->word);

	if(compare == -1){
		root->left = insertIntoTree(word, root->left);
	}
	else if(compare == 1){
		root->right = insertIntoTree(word, root->right);
	}
	else{
		root->rec++;
	}
  
  
	return root;
 
}

//check to see if the current node has child nodes
//a 1 is returned if either the left or right node is filled and a zero is returned if neither the left or right subtree has a node
int hasChild(TreeNode* treeNode){
	if(treeNode != NULL){
		if(treeNode->left != NULL){
			return 1;
		}
		if(treeNode->right != NULL){
			return 1;
        	}
	}

	return 0;
}
//two words are compared to see which one is greater or if they are equal
//1 is returned if a>b
//-1 is returned if a<b
//and zero is returned if a=b
int compareWords(const void *a, const void *b){

	if(strcmp(a, b) > 0){
		return 1;
	}
	else if(strcmp(a, b) < 0){
		return -1;
	}
	else{
		return 0;
	}
}
