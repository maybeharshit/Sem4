/*
Author: Harshit 
Lab 3: Program 3
Question:Write a program to implement solution to partition problem using brute-force 
technique and analyze its time efficiency theoretically. A partition problem takes 
a set of numbers and finds two disjoint sets such that the sum of the elements in 
the first set is equal to the second set. [Hint: You may generate power set]
*/

#include<stdio.h>

int isPossible(int sum, int arr[], int n){
	printf("sum: %d, n: %d\n", sum,n);
	if(sum == 0){
		return 1;
	}
	if(n == 0){
		return 0;
	}
	if(arr[n-1] > sum){
		return isPossible(sum,arr,n-1);
	}
	return (isPossible(sum,arr,n-1) || isPossible(sum-arr[n-1],arr,n-1));
}

int main(){

	int n;
	printf("Enter size of array\n");
	scanf("%d",&n);
	int arr[n];
	for(int i = 0; i < n; i++){
		scanf("%d",&arr[i]);
	}
	int sum = 0;
	for(int i = 0;i< n;i++){
		sum += arr[i];
	}
	if(sum % 2 != 0){
		printf("Partition Not Possible\n");
		return 1;
	}
	if(isPossible(sum/2,arr,n)){
		printf("Partitioning is possible\n");
	}
	else{
		printf("Partitioning not possible\n");
	}

	return 1;
}