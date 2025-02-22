void mergefnc(int* b,int* c,int* arr,int p,int q){
	int i=0,j=0,k=0;
	while(i<p && j<q){
		if(b[i] <= c[j]){
			arr[k] = b[i];
			i++;
		}
		else{
			arr[k] = c[j];
			j++;
		}
		k++;
	}
	if(i == p){
		for(int m = j;m<q;m++){
			arr[k] = c[m];
			k++;
		}
	}
	else{
		for(int m = i;m<p;m++){
			arr[k] = b[m];
			k++;
		}
	}
}
void mergesort(int* arr,int s){
	if(s == 1 || s == 0){
		return;
	}
	int* b = (int*)malloc(sizeof(int)*(s/2)+1);
	int* c = (int*)malloc(sizeof(int)*(s/2)+1);
	if(s>1){
		for(int i = 0;i<s/2;i++){
			b[i] = arr[i];
		}
		for(int i = s/2;i<s;i++){
			c[i-(s/2)] = arr[i];
		}
		//printf("Arr B\n");
		//printarr(b,s/2);
		//printf("Arr C\n");
		//printarr(c,s/2);
		mergesort(b,s/2);
		mergesort(c,s/2);
		mergefnc(b,c,arr,s/2,s/2);
		//printf("Arr B\n");
		//printarr(b,s/2);
		//printf("Arr C\n");
		//printarr(c,s/2);
	}
}
