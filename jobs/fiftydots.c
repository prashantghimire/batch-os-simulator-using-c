#include <stdio.h>
int main(){
	int i;
	for(i = 0 ; i < 50; i++){
		printf(". ");
		fflush(stdout);
		sleep(1);
	}
	printf("\n");
	return 0;
}