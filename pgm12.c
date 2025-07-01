#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX 20
int board[MAX], count = 0;

int isSafe(int row, int col){
	for(int i = 0 ; i < row; i++){
		if(board[i] == col || abs(board[i] - col) == abs(i - row)){
			return 0;
		}
	}
	return 1;
}

void solve(int row, int n){
	if(row == n){
		count++;
		printf("Solution %d:\n", count);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(board[i] == j) printf("S ");
				else printf("- ");
			}
			printf("\n");
		}
		return;
	}
	for(int col = 0; col < n; col++){
		if(isSafe(row, col)){
			board[row] = col;
			solve(row + 1, n);
		}
	}
}

int main(){
	int n;
	printf("Enter no of students(MAX 20): ");
	scanf("%d", &n);
	if(n < 1 || n > 20){
		printf("Please enter N b/w 1 and 20\n");
		return 1;
	}
	solve(0, n);
	if(count == 0){
		printf("No possible room allocation found\n");
	} else {
		printf("total no of valid room allocation: %d\n", count);
	}
	return 0;
}
