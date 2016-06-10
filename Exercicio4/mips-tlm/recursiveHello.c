#include <stdio.h>
#define LOCK_ADDRESS (100*1024*1024);
volatile int *lock = ( volatile int *) LOCK_ADDRESS;
volatile int procCounter = 0;

void AcquireLock(){
	while(*lock);
}

void ReleaseLock(){
	*lock = 0;
}

void recursiveHello(int n, int procNumber){
	if(n){
		printf("Hi, from processor %d\n", procNumber);
		recursiveHello(n-1, procNumber);
	}
}

int main(int ac, char *av[]){
	int procNumber, i;

	AcquireLock();
	procNumber = procCounter;
	procCounter++;
	ReleaseLock();
	
	if(procNumber %2)
		for(i = 0; i < 10000; i++);
	
	recursiveHello(5, procNumber);
	return 0;
}
