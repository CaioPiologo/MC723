#include <stdio.h>
#include <omp.h>

main(int argc, char *argv[])
{
  int n, i, count = 0;
  int parts;
  int nthreads, tid;
  n = atoi(argv[1]);

/* Fork a team of threads giving them their own copies of variables */
#pragma omp parallel private(tid, nthreads, parts) reduction(+:count)
  {

  /* Obtain thread number */
  tid = omp_get_thread_num();

  nthreads = omp_get_num_threads();
  parts = n/nthreads;
  //  Waits for the first thread to set the enviroment
  // while(parts == 0){}
  for (i = tid*parts; i < (tid+1)*parts; ++i){
  	if(primo(i)){
  		count++;
  	}
  }

  /* Only master thread does this */
  if (tid == nthreads - 1) 
    {
	   for (i = n - (n % nthreads); i <= n; ++i){
	  	if(primo(i)){
	  		count++;
	  	}
	   }   	
    }
  }  /* All threads join master thread and disband */

  printf("%d\n", count);
}
