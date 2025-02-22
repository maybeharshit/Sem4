int partition(int* arr,int low,int high){
	int pivot = arr[high];
	int i = low;
	for(int j = low;j<high;j++){
		if(arr[j] <= pivot){
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
		}
		
	}
	int temp = arr[i];
	arr[i] = arr[high];
	arr[high] = temp;
	return i;
}
void quicksort(int* arr,int low,int high){
	if(low>=high || low < 0){
		return;
	}
	int p = partition(arr,low,high);
	quicksort(arr,low,p-1);
	quicksort(arr,p+1,high);
}
