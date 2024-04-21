#include <stdio.h>

long factorial(int num)
{
	long result = 1;
	while (num > 1) {
		result *= num;
		num--;
	}
	return result;
}

int main()
{
	int num = 3;
	long result = factorial(num);
	printf("factorial(%d)=%ld\n", num, result);
	return 0;
}

