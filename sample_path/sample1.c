#include <stdio.h>

int main(){
	int i;
	int factorial = 1;
	for(i = 1; i < 11; i++){
		factorial *= i;
		printf("%d ", factorial);
		fflush(stdout);
		sleep(1);
	}
	printf("\nFactorial of 10 is : %d\n", factorial);
	return 0;
}