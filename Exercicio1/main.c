#include <stdio.h>
#include <omp.h>

main(int argc, char *argv[])
{
  int n, i, count = 0;
  int parts;
  int nthreads, tid;
  n = atoi(argv[1]);

/* Fork a team of threads giving them their own copies of variables */
#pragma omp parallel
{

	#pragma omp for reduction(+:count)
		for (i=2; i <= n; i++){
			if(primo(i)){
				count++;
			}
		}
  }  /* All threads join master thread and disband */

  printf("%d\n", count);
}
