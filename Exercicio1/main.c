#include <stdio.h>

main(int argc, char *argv[])
{
  int n, i, count = 0;
  n = atoi(argv[1]);

  for (i = 2; i <= n; ++i){
  	if(primo(i)){
  		count++;
  	}
  }
  printf("%d\n", count);
}
