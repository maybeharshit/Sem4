/*
Author: Harshit 
Lab 3: Program 2
Question: Write a program to implement brute-force string matching. Analyze its time 
efficiency
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void stringmatch(char* text, char* pattern){
	int flag = 0;
	for(int i = 0;i<strlen(text);i++){
		int j = 0;
		int z = i;
		while(j<strlen(pattern) && z < strlen(text)){
			if(text[z] != pattern[j]){
				flag = 1;
				break;
			}
			flag = 0;
			z++;
			j++;
		}
		if(flag == 0){
			printf("Pattern found in text \n");
			return;
		}
	}
	printf("Pattern Not Found\n");
}

int main(){

	char text[100];
	printf("Enter text\n");
	gets(text);
	char pattern[100];
	printf("Enter pattern\n");
	gets(pattern);
	stringmatch(text,pattern);
	return 1;

}