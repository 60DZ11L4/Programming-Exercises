/*****************************************
*	Array Filling by EAMP		*
*****************************************/

#include <stdlib.h>
#include <stdio.h>

int main(){
	int arr[11];
	for(int i = 1; i <=10; i++){
		printf("Enter the value %d: ", i);
		scanf("%d", &arr[i]);
	}
	printf("\nThe first position is equal to: %d\n", arr[0]);
	printf("The fifth position is equal to: %d\n", arr[5]);
	printf("The last position is equal to: %d\n", arr[10]);		
	return 0;
}
