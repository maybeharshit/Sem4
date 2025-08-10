c(sizeof(int)*no);
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