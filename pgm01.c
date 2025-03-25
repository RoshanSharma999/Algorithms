#include<stdio.h>
#define max 100000

int linearSearch(int arr[], int size, int key, int *count){
	*count = 0;
	for(int i = 0; i < size; i++){
		(*count)++;
		if(arr[i] == key) return i;
	}
	return -1;
}

int binarySearch(int arr[], int left, int right, int key, int *count){
	*count = 0;
	while(left <= right){
		(*count)++;
		int mid = left + (right-left) / 2;
		if(arr[mid] == key) return mid;
		else if(arr[mid] < key) left = mid+1;
		else right = mid - 1;
	}
	return -1;
}

int main(){
	int size, key, count;
	printf("Enter number of elements: ");
	scanf("%d", &size);
	int arr[max];
	// For large number of elements, just assign value arr[i] = i+1, instead of reading
	printf("Enter elements in ascending order: \n");
	for(int i = 0; i < size; i++) scanf("%d", &arr[i]);
	printf("Enter a number to search: ");
	scanf("%d", &key);
	
	int linIdx = linearSearch(arr, size, key, &count);
	if(linIdx != -1){
		printf("Linear Search: Element found at index %d with %d comparisions\n", linIdx, count);
	} else {
		printf("Linear Search: Element not found\n");
	}
	
	int binIdx = binarySearch(arr, 0, size-1, key, &count);
	if(binIdx != -1){
		printf("Binary Search: Element found at index %d with %d comparisions\n", binIdx, count);
	} else {
		printf("Binary Search: Element not found\n");
	}
	
	return 0;
}

// Output
/*
	Number of elements : Comaprisions in Linear Search : Comparisions In Binary Search
	05 : 04 : 02
	10 : 07 : 04
	20 : 15 : 02
	30 : 19 : 03
*/

