/*
Author: Harshit 
Question:Write a program to construct a binary tree to support the following operations.
Assume no duplicate elements while constructing the tree.
i. Given a key, perform a search in the binary search tree. If the key is found
then display “key found” else insert the key in the binary search tree.
ii. Display the tree using inorder, preorder and post order traversal methods
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;
struct node{
	int key;
	struct node* left;
	struct node* right;
};

Node* createNode(int key){
	Node* ret = (Node*)malloc(sizeof(Node));
	if(ret!=NULL){
		ret->key = key;
		ret->left = NULL;
		ret->right = NULL;
	}
	return ret;
}

void Tree(Node** root, int key){
	//printf("working");
	if ((*root) == NULL){
		*root = createNode(key);
	}
	else if((*root)->key > key){
		Tree((&(*root)->left),key);
	}
	else{
		Tree((&(*root)->right),key);
	}
}

void Post(Node* root){
	if(root == NULL) return;
	Post(root->left);
	Post(root->right);
	printf("%d ", root->key);
}
void Pre(Node* root){
	if(root == NULL) return;
	printf("%d ", root->key);
	Pre(root->left);
	Pre(root->right);
	
}
void In(Node* root){
	if(root == NULL) return;
	In(root->left);
	printf("%d ", root->key);
	In(root->right);
	
}



int main(){
	int n = 1;
	int choice;
	int key;
	Node* root = NULL;
	printf("1.Enter Key\n2.Display\n3.Exit\n");
	while(n == 1){
		scanf("%d",&choice);
		switch(choice){
			case 1:
				scanf("%d",&key);
				printf("Inserting %d in the tree\n", key);
				Tree(&root,key);
				break;
			case 2:
				printf("Inorder: ");
				In(root);
				printf("\nPreorder: ");
				Pre(root);
				printf("\nPost: ");
				Post(root);
				printf("\n");
				break;
			case 3:
				printf("Exiting\n");
				exit(0);
				break;

		}

	}

	return 1;
}