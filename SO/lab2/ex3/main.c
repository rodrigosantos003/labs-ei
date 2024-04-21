#include <stdio.h>
#include "math.h"

int main(){
	int num = 0;

	printf("Enter a number: ");
	scanf("%d", &num);

	printf("\nThe square of the number is: %d", square(num));
	printf("\nThe cube of the number is: %d", cube(num));

	return 0;
}
