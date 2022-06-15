/****************************************************************
*								*
*	Pascal Triangle by Edoardo Alonso Martinez Perez	*
*			Recursive - Array			*
*								*
*****************************************************************/

									// [Inclusion of required libraries and headers]
#include <stdio.h>
#include <stdlib.h>

									// [Definition of calculation function]
									// [It requires the rows number, and also the columns number]

double calculation(int row, int col);
									// [Main function]

int main(){
	system("clear");
										// [Definition of local variables]
	
	int r, c, spaces, position;
	int rows, i, columns = 0;
	
	printf("\nEnter a positive integer: ");				// [An integer value representing the number of rows is requested]
	scanf("%d", &rows);						// [We assign this input to our row variable]
	

									// [Loop to set the size required by the array (sum)]

	for (i = 1; i <= rows; ++i) {
		columns += i;
	}
	printf("Columns: %d\n\n", columns);				// [Print by console of the required columns, amount of array data]

	double triangle[columns];					// [Definition of the array size based on the number of columns]
	
	for (r = 0; r <= rows; r++){
		for (spaces = rows - r; spaces > 0; spaces--)		// [Loop for console printing of dynamic spaces]
			printf(" ");				
		for (c = 0; c <= r; c++){				// [Loop to generate and print the pascal's triangle numbers]
			triangle[position] = calculation(r, c);		// [Calling the Calculation function, passing current values of arguments]
			printf("%.0lf ", triangle[position]);		// [Printing the values of current position in the array called triangle]
		}	
		printf("\n");
	}
	printf("\n");
	return 0;							// [End program]
}

									// [Definition of calculation function]

double calculation(int row, int col) {					// [This section is useful, when we are leading with the limits]
	if (row >= 0 && (col==0 || col==row))
		return 1;						// [Cause always we need a 1...]
	else
		return calculation(row-1, col) + calculation(row-1, col-1);	// [Recursive function method to sum previous numbers]
}

/************************************************************************************************************************************************
*																		*
*	Pascal's triangle in honor of the French philosopher and mathematician Blaise Pascal, who introduced this expression in 1654		*
*	although this triangle was already known since ancient times. Below we will delve into the history of this peculiar triangle.		*
*																		*
*	To construct Pascal's triangle we start with the apex of the triangle, which is always a 1, and then we calculate the rows below.	*
*	Each number in the subsequent rows corresponds to the sum of the two numbers just above it, except for the ends which are always 1.	*
*																		*
*	Therefore, in our recursive function Calculation, an exception case is created for the moment when it is required to generate only 1.	*
*	Likewise, the way to generate the subsequent numbers we use the same function recursively to be able to add the values before it.	*
*																		*
*************************************************************************************************************************************************/

