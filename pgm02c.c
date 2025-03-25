#include<stdio.h>
#include<time.h>

void even(int rows, int cols, int matrix[rows][cols]){
	printf("Even elements: \n");
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			if(matrix[i][j]%2 == 0) printf("%d\t", matrix[i][j]);
		}
	}
	printf("\n");
}

int main(){
	int rows, cols;
	printf("Enter number of rows: ");
	scanf("%d", &rows);
	printf("Enter number of columns: ");
	scanf("%d", &cols);
	
	int matrix[rows][cols];
	// For large number of elements, just assign some values, instead of reading
	printf("Enter %d matrix elements: \n", rows*cols);
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			scanf("%d", &matrix[i][j]);
		}
	}
	
	clock_t start = clock();
	even(rows, cols, matrix);
	clock_t end = clock();
	double cpuTime = (double)(end - start)/CLOCKS_PER_SEC;
	printf("Time taken: %lf\n", cpuTime);
	return 0;
}

// Output
/*
	Order of matrix : Time taken(sec)
	1x1 : 0.000010
	2x2 : 0.000014
	4x4 : 0.000021
	6x6 : 0.000027
*/

