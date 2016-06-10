#include <stdio.h>
int main(){
	printf("Hello World! ");
	
	volatile int* mem = (int *)(100*1024*1024);
	
	*mem = 42;

	printf("%d\n", *mem);
	printf("%d\n", *mem);
	printf("%d\n", *mem);
	return 0;
}
