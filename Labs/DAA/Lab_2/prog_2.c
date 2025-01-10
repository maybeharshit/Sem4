/*
Author: Harshit 
Question:Write a program to find GCD using middle school method and analyze its time
efficiency.
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int isPrime(int k){
	if(k == 2){
		return 1;
	}
	if (k<=1 || k % 2 == 0){
		return 0;
	}
	
	for(int i =3;i<=sqrt(k); i+=2){
		if(k%i == 0){
			return 0;;
		}
	}
	return 1;
}

int nprimefac(int k){
	if(k == 1 || k == 0){
		return -1;
	}
	if(k == 2 || k == 3){
		return 1;
	}
	int count = 0;	
	for(int i=2;i<=k;i++){
		int x = i;
		int temp = k;
		while(isPrime(x) == 1 && temp % x == 0){
			count++;
			temp /= x;
		}
	}
	return count;
}

int* makearr(int k){
	int* a = (int*)malloc(sizeof(int));
	a[0] = k;
	if(isPrime(k)){
		return a;
	}
	int no = nprimefac(k);
	int* arr = (int*)malloc(sizeof(int)*no);
	for(int i = 0;i<no;i++){
		arr[i] = 0;
		
	}
	int temp = k;
	int j = 2;
	int i = 0;
	int last_i; 
	while(i<no){
		while(temp % j == 0 && isPrime(j)){
			arr[i++] = j;
			temp /= j;
			if(temp %j == 0){
				i;
			}
		}
		j++;
	}
	return arr;
}
int givegcd(int* a1, int* a2,int n1,int n2){
	if(n1 == 1 && n2 == 1){
		return 1;
	}
	int c1 = 0,c2 = 0;
	int gcd = 1;
	while(c1<n1 && c2<n2){
		if(a1[c1] == a2[c2]){
			gcd *= a1[c1];
			c1++;
			c2++;
		}
		else if(a1[c1] > a2[c2]){
			c2++;
		}
		else{
			c1++;
		}
	}
	return gcd;
}
int main(){
	int m,n;
	printf("Enter two number for computing gcd\n");
	scanf("%d %d",&m,&n);
	printf("%d",givegcd(makearr(m),makearr(n),nprimefac(m),nprimefac(n)));
	return 1;
}