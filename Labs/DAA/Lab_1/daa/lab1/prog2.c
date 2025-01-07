/*
Author: Harshit 
DAA Lab 1 Question 2
Question:Write a program to implement the following graph representations and display
them.
i. Adjacency list
ii. Adjacency matrix
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;

struct node{
	int a;
	struct node* next;
};

Node* createNode(int a){
	Node* n = (Node*)malloc(sizeof(Node));
	if(n != NULL){
		n->a = a;
		n->next = NULL;
	}
	return n;
}

void List(Node** head, int a){
	if(*head == NULL){
		*head = createNode(a);
		return ;
	}
	List(&((*head)->next),a);
}

void printList(Node* head){
	if(head->next == NULL) {
		printf("%d->NULL",head->a);
		return;
	}
	printf("%d->",head->a);
	printList(head->next);
}

int main(){

	int n;
	printf("Enter number of nodes in the graph\n");
	scanf("%d",&n);
	int adjmat[n][n];
	for(int i=0;i<n;i++){
		for(int j = 0;j<n;j++){
			adjmat[i][j] = 0;
		}
	}
	int neigh = 0;
	for(int i=0;i<n;i++){
		int j = 0;
		printf("Enter neighbour of %d(-1 for exit)\n" ,(i+1));
		while(j != -1){
			printf("Enter Node\n");
			scanf("%d",&j);
			if(j == -1) break;
			if(j-1 == i) continue;
			adjmat[i][j-1] = 1;
			

		}
	}
	
	Node* nodes[n];
	for(int i =0;i<n;i++){
		nodes[i] = NULL;
		List(&nodes[i],i+1);
	}
	for(int i =0;i<n;i++){
		for(int j=0;j<n;j++){
			if(adjmat[i][j] == 1) List(&nodes[i],j+1);
		}
	}
	printf("Adjacency List\n");
	for(int i =0;i<n;i++){
		printList(nodes[i]);
		printf("\n");
	}
	printf("Adjacency matrix\n");
	printf("  ");
	for(int i =0;i<n;i++){
		printf("%d ",i+1);
	}
	printf("\n");
	for(int i =0;i<n;i++){
		printf("%d " ,i+1);
		for(int j =0;j<n;j++){
			printf("%d ",adjmat[i][j]);
		}
		printf("\n");
	}

	
	return 1;
}