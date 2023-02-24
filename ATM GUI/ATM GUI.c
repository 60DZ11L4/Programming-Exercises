
/**************************************
 *            ATM Interface           *
 **************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_LEN 128


void print_image(FILE * fptr);
int main(void){

// VARIABLE DELCARATION
	int	option		=	0;
	double	A		=	1000;
	double	B		=	0;
	float	result		=	0;
	char	answer;
// SYSTEM TIME CONFIGURATION
	time_t seconds;
	struct tm *timeStruct;
	seconds = time(NULL);
	timeStruct = localtime(&seconds);
// GUI PRINTING PART_A

	do{
	system("clear");
	char *filename = "GUI PART_A.txt";
	FILE *fptr = NULL;
	if((fptr = fopen(filename, "r")) == NULL){
		fprintf(stderr, "error opening %s\n", filename);
	return 1;
	}
	print_image(fptr);
	fclose(fptr);
// GUI PRINTING PART_B
	printf("\tWELCOME TO LINUX  ATM BANK TERMINAL SERVICE\n");
	printf("\n\t\tCURRENT HOUR : %.2d:%.2d\n", timeStruct->tm_hour, timeStruct->tm_min);
	printf("\t..........................................\n");
	printf("\t\tMENU OPTIONS\n\n");
	printf("\t1 : DEPOSIT MONEY\n");
	printf("\t2 : WITHDRAW MONEY\n");
	printf("\t3 : CHECK BALANCE\n");	
	printf("\t4 : PRINT TICKET\n");
	printf("\t5 : EXIT\n");
	printf("\t..........................................\n");


// ENTRY OF OPERATOR & VALIDATION
	printf("\n\tDIGIT THE OPERATION NUMBER TO DO: ");
	scanf("%d", &option);

// ATM OPERATIONS & BALANCE
	switch(option){
		case 1:
			printf("\n\tENTER THE AMOUNT TO DEPOSIT: ");
			if (scanf("%lf", &B)){
			}
				else{
					printf("\n\tNOT VALID INPUT TRY AGAIN...\n\n");
					return 0;
			}
			printf("\n\t>>APPROVED<<\n");
			result = A + B;
			A = result;
			break;
		case 2:
			printf("\n\tENTER THE AMOUNT TO WITHDRAWN: ");
			if (scanf("%lf", &B)){
			}
				else{
					printf("\n\tNOT VALID INPUT TRY AGAIN...\n\n");
					return 0;
			}
			if (B > A){
				printf("\n\t>>INSUFFICIENT BALANCE<<\n");
			}else{
				printf("\n\t>>APPROVED<<\n");
				result = A - B;
				A = result;
			}
			break;
		case 3:
			break;
		case 4:
			printf("\n\tPRINTING TICKET...\n");
			char *filename = "TICKET.txt";
			// OPEN THE TICKET FILE FOR WRITING
			FILE *fp = fopen(filename, "w");
			if (fp == NULL)
			{
			printf("Error opening the file %s", filename);
			return -1;
			}
			// WRITING IN THE TICKET FILE
			fprintf(fp, "\n\t\tCurrent time : %.2d:%.2d\n", timeStruct->tm_hour, timeStruct->tm_min);
			fprintf(fp, "\nATM LINUX TERMINAL SERVICE\nYOUR CURRENT BALANCE IS: $%.2lf\n", A);
			// CLOSE THE FILE
			fclose(fp);
			break;
		case 5:
			printf("\n\tExiting...\n\n");
			return 0;
			
		default:
			printf("\n\tINVALID OPERATION, EXITING TRY AGAIN...\n\n");
			return 0;		
	}
	
	printf("\n\tTHE CURRENT BALANCE IS: $[%.2f]\n", A);
	printf("\n\t..........................................\n");
	printf("\n\tWould you like to continue?\t [Y/n]: ");
	scanf(" %c", &answer);
	}while(answer == 'Y' | answer == 'y');

	printf("\n\tExiting...\n\n");
	return 0;
}


void print_image(FILE * fptr){
	char read_string[MAX_LEN];
	while(fgets(read_string, sizeof(read_string), fptr) != NULL)
		printf("%s", read_string);
}
