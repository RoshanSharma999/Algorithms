#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int selectionSort(int arr[], int n, int count){
	int minIdx = -1;
	for(int i = 0; i < n-1; i++){
		minIdx = i;
		for(int j = i+1; j < n; j++){
			if(arr[j] < arr[minIdx]){
				minIdx = j;
			}
		}
		if(minIdx != i){
			int temp = arr[i];
			arr[i] = arr[minIdx];
			arr[minIdx] = temp;
			count++;
		}
	}
	return count;
}

void randomGen(int arr[], int n){
	for(int i = 0; i < n; i++){
		arr[i] = rand()%1000;
	}
}

int main(){
	int n, count = 0;
	printf("Enter number of elements: ");
	scanf("%d", &n);
	int arr[n];
	randomGen(arr, n);
	clock_t start = clock();
	count = selectionSort(arr, n, count);
	clock_t end = clock();
	// print sorted array if needed
	/*
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	*/
	printf("Count: %d\n", count);
	double cpuTime = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Time taken = %lf seconds\n", cpuTime);
	return 0;
}
