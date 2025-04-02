#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

int bubbleSort(int arr[], int n, int count){
	bool flag;
	for(int i = 0; i < n-1; i++){
		flag = false;
		for(int j = 0; j < n-i-1; j++){
			if(arr[j] > arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				count++;
				flag = true;
			}
		}
		if(flag == false) break;
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
	count =  bubbleSort(arr, n, count);
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
