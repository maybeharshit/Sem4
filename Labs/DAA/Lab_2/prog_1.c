/*
Author: Harshit 
Question:Write a program to find GCD using consecutive integer checking method and
analyze its time efficiency.
*/

#include<stdio.h>


int mini(int m,int n){
	if(m>=n){
		return n;
	}
	return m;
}

int main(){
	int m,n;
	printf("Enter two number for computing gcd\n");
	scanf("%d %d",&m,&n);
	int t = mini(m,n);
	while(t != 0 )
		{if(m%t == 0){
			if(n%t == 0){
				printf("GCD of %d %d is %d\n",m,n,t);
				return 1;
			}
	
		}
		t--;
	}


	return 1;


}