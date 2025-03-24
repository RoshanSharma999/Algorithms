#include<stdio.h>
#include<time.h>
#define max 100000

void sumOfArray(int arr[], int size){
	int sum = 0;
	clock_t start = clock();
	for(int i = 0; i < size; i++) sum += arr[i];
	clock_t end = clock();
	printf("Sum of array elements = %d\n", sum);
	printf("Time taken = %f\n", ((double)(end - start)/CLOCKS_PER_SEC));
}

int main(){
	int size, arr[max];
	printf("Enter number of elements: ");
	scanf("%d", &size);
	// just assign some values
	for(int i = 0; i < size; i++) arr[i] = i+1;
	sumOfArray(arr, size);
	return 0;
}

// Output(varies on different systems)
/*
	Number of elements : Time Taken(sec)
	1 : 0.000001
	10 : 0.000001
	100 : 0.000001
	1000 : 0.000005
	10000 : 0.000029
	100000 : 0.000370
*/
