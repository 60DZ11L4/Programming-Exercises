/************************************************
 *  Random Matrix by functions - Maximum & MRV  *
 ************************************************/
 
#include	<stdlib.h>
#include	<stdio.h>
#include	<time.h>
#define		SIZE 10

int rows		=	10;
int columns		=	10;
int dg			=	3;
int upper		=	200;
int lower		=	1;
int maximum;
int maxFrequency 	=	0;
int mostRepeated 	=	0;



int aleatory(int lower, int upper){
	int x = rand()% 200 + 1;
	return x;
}

void max(int arr[SIZE][SIZE], int rows, int columns){
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < columns; j++){
			if (arr[i][j] >= maximum){
				maximum = arr[i][j];
			}
		}
	}
	printf("\nMaximum value in matrix: %d\n\n", maximum);
}

void repeated(int arr[SIZE][SIZE], int rows, int columns){
	int maxFrequency = 0;
	int mostRepeated = 0;
	
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			int frequency = 0;
			for(int m = 0; m < 10; m++){
				for(int n = 0; n < 10; n++){
					if(arr[i][j] == arr[m][n]){
						frequency ++;
					}
				}
			}
			if(maxFrequency < frequency){
				maxFrequency = frequency;
				mostRepeated = arr[i][j];
			}
		}
	}
	printf("Most repeated number in matrix: %d | Freq: %d\n\n", mostRepeated, maxFrequency);
}

int main(){
	system("clear");
	srand(time(NULL));
	int arr[rows][columns];

	printf("\n\nMatrix\n\n");

	for (int i = 0; i < rows; i++){
		for (int j = 0; j < columns; j++){
			arr[i][j] = aleatory(lower, upper);
			printf("[%0*d] ", dg, arr[i][j]);
		}
		printf("\n");
	}
	
	max(arr, rows, columns);
	repeated(arr, rows, columns);
	return 0;
}
