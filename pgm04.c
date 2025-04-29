#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct{
	int isbn;
} Book;

void merge(Book arr[], int left, int mid, int right){
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;
	Book* L = (Book*) malloc(n1 * sizeof(Book)); 
	Book* R = (Book*) malloc(n2 * sizeof(Book)); 
	for(i = 0; i < n1; i++) L[i] = arr[left + i];
	for(j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
	i = j = 0;
	k = left;
	while(i < n1 && j < n2){
		if(L[i].isbn <= R[j].isbn) 
			arr[k++] = L[i++];
		else 
			arr[k++] = R[j++];
	}
	while(i < n1) arr[k++] = L[i++];
	while(j < n2) arr[k++] = R[j++];
	free(L);
	free(R);
}

void mergeSort(Book arr[], int left, int right){
	if(left < right){
		int mid = left + (right - left) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

void genRanBooks(Book arr[], int n){
	for(int i = 0; i < n; i++) arr[i].isbn = rand()%9000 + 1000;
}

int main(){
	int n;
	printf("Enter number of books: ");
	scanf("%d", &n);
	Book *books = (Book*) malloc(n * sizeof(Book));
	if(!books){
		printf("Memory allocation failed\n");
		return 1;
	}
	srand(time(0));
	genRanBooks(books, n);
	clock_t start = clock();
	mergeSort(books, 0, n - 1);
	clock_t end = clock();
	double cpuTime = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Time taken to sort: %lf\n", cpuTime);
	free(books);
	return 0;
}
