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
#include "GreedyOBST.h"

char *Words[2000];
double Prob[2000];
int in = 1;
/*
GreedyOBST takes in the user file and the user string to scan the greedy optimal binary search tree with. The words in the text file are sorted in order alphebetically. Once the Greedy Optimal Binary Search Tree has been created using the recursive function the search function scans and compares each node with the users input string until the correct node is found. Every comparison results in the function displaying the probability of the word relative to the total number of words to the terminal. 
*/
void GreedyOBST(FILE *file, char *userStr){

	userStr[strlen(userStr)] = '\0';
	Node *root = NULL;
	Node *Randroot = NULL;
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
						root = IntoTree(realWord, root);
						numChar = 0;
						totalWords++;
					}
				}
			}
		}
	}
	fclose(file);
	Randroot = root;
	trav(totalWords, Randroot);
	int k = in;
	Node *GreedyOBST = createGOBST(1, k-1);
	scanTree(GreedyOBST, userStr);
	destroyTree(root);
	destroyTree(GreedyOBST);

}
//take the current root and create a node if it is a leaf
//sort the words in either the left subtree, right subtree or the word is a copy and thus increment the recurrence variable in the struct
//the root node is returned 
Node *IntoTree(char * word, Node * root){
	int numChildren = hasC(root);
	int nodeHeight = getH(root);
	if (numChildren == 0 && nodeHeight == 0) { 
		Node* temp = createNode(word,1,1);
        	return temp; 
	}
	int comp = 0;
	comp = compare(word, root->word);

	if(comp == -1){
		root->left = IntoTree(word, root->left);
	}
	else if(comp == 1){
		root->right = IntoTree(word, root->right);
	}
	else{
		root->rec++;
	}
  
  
	return root;
 
}
//a tree node is created when given the word field the total field and the number of recurrences as a field
//the new tree node is returned
Node *createNode(char *word, float total, float rec){
	Node * treenode = (Node*)malloc(sizeof(Node));
	char *nWord = malloc(sizeof(char)*(strlen(word)+1));
	strcpy(nWord, word);
	treenode->total = total;
	treenode->rec = rec;
	treenode->word = nWord;
	treenode->right = NULL;
	treenode->left = NULL;
	return treenode;
}
//the current node is checked to see if it has children and it is not a leaf
//first the left subtree is traversed and then the right recursively
//the keywords are sorted into Words[] and the the words probability is put into Prob[]
//if the current node is a leaf the function returns
void trav(int totalWords, Node *root){
	int numChildren = hasC(root);
	int nodeHeight = getH(root);
	if(root->left != NULL && numChildren == 1 && nodeHeight != 1){
		trav(totalWords, root->left);
	}
	Words[in] = root->word;
  	Prob[in] = (float)root->rec/totalWords;
    	in++;
	if(root->right != NULL && numChildren == 1 && nodeHeight != 1){
		trav(totalWords, root->right);
	}
	if(numChildren == 0 && nodeHeight == 1){
	        return;
	}
}
//obtain the height of the current node relative to the tree
int getH(Node* treeNode){
	if(treeNode == NULL){
        	return 0;
	}

	int leftHeight = getH(treeNode->left) + 1;
	int rightHeight = getH(treeNode->right) + 1;

	if(leftHeight > rightHeight){
		return leftHeight;
	}
	else{
	        return rightHeight;
	}
}
//search the greedy optimal binary search tree for the user word
//print each word that is compared along with its probability 
//the direction of the next subtree is also printed
Node * scanTree(Node * root, char * word) {
	if (hasC(root) != 0){
		if (compare(word, root->word) == 0) {
		// same: update the fequency of the word given
		printf("Compared with %s (%.4f), found.\n", root->word, root->total);
		} 
		else if (compare(word, root->word) == 1) {
			// go right
			printf("Compared with %s (%.4f), go right subtree.\n", root->word, root->total);
			root->right = scanTree(root->right, word);
		} 
		else {
			// go left
			printf("Compared with %s (%.4f), go left subtree.\n", root->word, root->total);
			root->left = scanTree(root->left, word);
		}
	} 
	else {
	    printf("not found!\n");
	}
	return root;
}

//check to see if the current node has child nodes
//a 1 is returned if either the left or right node is filled and a zero is returned if neither the left or right subtree has a node
int hasC(Node* treeNode){
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
int compare(const void *a, const void *b){

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
//a recursive function to create a greedy binary search tree
//the index for the word containing the highest probability is found between two max and min index points
//the word and the probability associated with this index is the split for a new left and right subtree
//this continues recursively
//the greedy optimal binary search tree is returned 
Node * createGOBST(int i, int j){
	Node *newNode;
	int highestprobIndex = 0;
	highestprobIndex = probIndex(i,j);
	if(i <= j){
		// find the root
		char *newWord = Words[highestprobIndex];
		newNode = createNode(newWord,Prob[highestprobIndex],1);
		newNode->left = createGOBST(i,highestprobIndex-1);
		newNode->right = createGOBST(highestprobIndex+1, j);
	}
	else{
		newNode = NULL;
	}
	return newNode;
}
//the index for the word containing the highest probability is returned
int probIndex(int i, int j){
	double temp = 0;
	int ind = 0;
	int z = 0;
	for(z = i; z <= j; z++){
		if(temp < Prob[z]){
			temp = Prob[z];
			ind = z;
		}
	}
	return ind;
}
//the memory for each node is free'd one at a time recursively
void destroyTree(Node * node){
	int numChildren = hasC(node);
	int nodeHeight = getH(node);
	if ( numChildren == 0 && nodeHeight == 1 ) { 
		return; 
	}
	if(node->right != NULL && numChildren == 1 && nodeHeight != 1){
		destroyTree(node->right);
	}
	if(node->left != NULL && numChildren == 1 && nodeHeight != 1){
		destroyTree(node->left);
	}
	free(node->word);
	free(node);
}
