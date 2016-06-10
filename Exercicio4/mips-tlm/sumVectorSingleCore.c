#include <stdio.h>
#include <stdlib.h>
#define LOCK_ADDRESS (100*1024*1024);
volatile int *gLock = ( volatile int *) LOCK_ADDRESS;
volatile int lock1 = 0;
volatile int procCounter = 0;

volatile int totalSum = 0;
volatile int size = 0;
volatile int *array;
volatile int done = 0;

void AcquireGlobalLock(){ while(*gLock){}}
void ReleaseGlobalLock(){*gLock = 0;}

void AcquireLocalLock(volatile int *lock){
	int i;
	AcquireGlobalLock();
	while(*lock){
		ReleaseGlobalLock();
   	for(i=0; i < 10; i++) {}
   	AcquireGlobalLock();
   }
	*lock = 1;
	ReleaseGlobalLock();
}

void ReleaseLocalLock(volatile int *lock){
	AcquireGlobalLock();
	*lock = 0;
	ReleaseGlobalLock();
}

void main2(){
	int procNumber, n = 1000001, sum = 0;
		int i;
		int array_aux[1000001];
		AcquireLocalLock(&lock1);
		procNumber = procCounter;
		procCounter++;
		sum = totalSum;
		if(procNumber == 0){
//			scanf("%d", &n);
//			array_aux = malloc(n*sizeof(int));
			for(i = 1; i < n; i++)
				array_aux[i] = i;
//				scanf("%d", &array_aux[i]);
			array = array_aux;
		}
		ReleaseLocalLock(&lock1);
		
		for(i = 0; i < n; i++){
			sum += array[i];
		}
	
		AcquireLocalLock(&lock1);
		totalSum += sum;
		ReleaseLocalLock(&lock1);
		
		if(procNumber == 0){
//			while(done < 2){}
			printf("Soma total = %d\n", totalSum);
		}
}

int main(int ac, char *av[]){
	main2();	
	return 0;
}
