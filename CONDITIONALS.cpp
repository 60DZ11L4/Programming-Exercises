#include <stdio.h>
using namespace std;

int main(){
int t;
	printf("Enter the time (1-24): ");
	scanf("%d", &t);
	printf("\n");
	if(t > 0 && t <= 3)
		printf("Good Night\n");
	else if(t > 3 && t < 12)
		printf("Good Morning\n");
	else if(t == 12)
		printf("Good Noon\n");
	else if(t > 12 && t <= 15)
		printf("Good AfterNoon\n");
	else if(t > 15 && t < 20)
		printf("Good Evening\n");
	else if(t >= 20 && t <= 24)
		printf("Good Night\n");
	else
		printf("Unknown time!\n");
	return 0;
}

