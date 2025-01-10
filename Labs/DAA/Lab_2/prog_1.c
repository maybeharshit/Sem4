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
/*
After analysis we see that the time complexity of this
program is O(min(m,n)) since the program runs till t 
reaches 0 and the value of t is set to the value of min(m,n)
*/
