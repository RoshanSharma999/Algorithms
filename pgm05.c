#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}

void genRanIds(int arr[], int n){
	for(int i = 0; i < n; i++) arr[i] = rand() % 1000;
}

int partition(int arr[], int low, int high){
	int pivot = arr[high];
	int i = (low - 1);
	for(int j = low; j < high; j++){
		if(arr[j] <= pivot){
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return i + 1;
}

void quickSort(int arr[], int low, int high){
	if(low < high){
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

int main(){
	int n;
	printf("Enter number of file id's: ");
	scanf("%d", &n);
	int* fileId = (int*) malloc(n * sizeof(int));
	if(fileId == NULL){
		printf("Memory allocation failed\n");
		return 1;
	}
	srand(time(NULL));
	genRanIds(fileId, n);
	clock_t start = clock();
	quickSort(fileId, 0, n - 1);
	clock_t end = clock();
	double cpuTime = (double)(end-start) / 	CLOCKS_PER_SEC;
	printf("Time taken: %lf\n", cpuTime);
	free(fileId);
	return 0;
}
