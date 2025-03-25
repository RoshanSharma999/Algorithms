#include<stdio.h>
#include<time.h>

void decToBin(int n){
	if(n == 0){
		printf("(to binary): %d\n", n);
		return;
	}
	int binary[32];
	int i = 0;
	while(n > 0){
		binary[i] = n%2;
		n = n/2;
		i++;
	}
	printf("(to binary): ");
	for(int j = i-1; j >= 0; j--){
		printf("%d", binary[j]);
	}
	printf("\n");
}

int main(){
	int n;
	printf("Enter a decimal number: ");
	scanf("%d", &n);
	clock_t start = clock();
	decToBin(n);
	clock_t end = clock();
	double cpuTime = (double)(end - start)/CLOCKS_PER_SEC;
	printf("Time taken: %lf\n", cpuTime); 
	return 0;
}

// Output
/*
	Decimal number : Time taken(sec)
	8 : 0.000032
	9826 : 0.000034
	846792 : 0.000038
	4267824 : 0.000039
*/

