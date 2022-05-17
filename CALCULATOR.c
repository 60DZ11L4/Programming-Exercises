
/*********************************************************
 *		Calculator Program by EAMP		 *
 *********************************************************/

#include	<stdio.h>
#include	<stdlib.h>
#include	<stdbool.h>

int main(){
//VARIABLES DECLARATION
	int	option		=	0;
	double	A		=	0;
	double	B		=	0;
	float	result		=	0;
	char	answer;

//MENU PRINTING
	do{
	system("clear");
	printf("\n\n\t..................................");
	printf("\n\t*****CALCULATOR - MENU OPTION*****\n\n\t1 : ADDITION\n\t2 : SUBTRACTION\n\t3 : MULTIPLICATION\n\t4 : DIVISION");
	printf("\n\t..................................\n");

//ENTRY OF VALUES & VALIDATION
	printf("\n\tEnter the first value: ");
	if (scanf("%lf", &A)){
	}
		else{
			printf("\n\tNot valid input, try again...\n\n");
		return 0;
	}
	printf("\tEnter the second value: ");
	if (scanf("%lf", &B)){
	}
		else{
			printf("\n\tNot valid input, try again...\n\n");
		return 0;
	}

//ENTRY OF OPERATOR & VALIDATION
	printf("\n\tDigit the number of operation to compute: ");
	scanf("%d", &option);

	if(1 <= option && option <= 4){
		//printf("Valid option\n");
	}else{
		printf("\tInvalid operation, try again...\n\n");
		return 0;
	}

//OPERATIONS & RESULTS
	if(option == 1){
		result = A + B;
		printf("\a\n\tTHE ADDITION RESULT IS: [%.2f]\n", result);
	}
	if(option == 2){
		result = A - B;
		printf("\a\n\tTHE SUBTRACTION RESULT IS: [%.2f]\n", result);
	}
	if(option == 3){
		result = A * B;
		printf("\a\n\tTHE MULTIPLICATION RESULT IS: [%.2f]\n", result);
	}
	if(option == 4){
		if(B == 0){
			printf("\a\n\tIt is not possible to divide by 0, try again...\n\n");
			return 0;
		}else{
			result = A / B;
			printf("\a\n\tTHE DIVISION RESULT IS: [%.2f]\n", result);
		}
	}
	printf("\n\t..................................\n");
	printf("\n\tWould you like to continue?\t [Y/n]: ");
	scanf(" %c", &answer);
	}while(answer == 'Y' | answer == 'y');

	printf("\n\tExiting...\n\n");
	return 0;
}
