/*
Author: Harshit 
Lab 3: Program 1
Question:Write a program to sort set of integers using bubble sort. Analyze its time 
efficiency. Obtain the experimental result of order of growth. Plot the result for 
the best and worst case.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubblesort(int* arr, int n){
	
	int temp;
	for(int i = 0;i<n-1;i++){
		for(int j = i+1;j<n;j++){
			if(arr[i] > arr[j]){
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	printf("\nAfter sorting\n");
}

int main(){
	srand(time(0));
	int n;
	printf("Enter size of array\n");
	scanf("%d",&n);
	//n = (rand() % 100) + 1;
	if(n == 0){
		printf("Cannot sort an empty array\n");
		return 0;
	}
	int arr[n];
	printf("Enter Elements:\n");
	for(int i = 0; i < n; i++){
		//arr[i] = (rand() % 100);
		scanf("%d",&arr[i]);
	}
	for(int i = 0; i < n; i++){
		printf("%d\t",arr[i]);
	}
	bubblesort(arr,n);
	for(int i = 0; i < n; i++){
		printf("%d\t",arr[i]);
	}
	printf("\n");
	

	return 1;
}
