#include <stdio.h>
#include <stdlib.h>
#include <Math.h>

int main(int argc, char *argv[]){
    int i,j;
    int *numbers;
    int count = 0;
    int n = atoi(argv[1]);
    int nthAproximation;
    int lastPrime = 2;
    double logN;

    /*calculates nth aproximation*/
    if(n > 6){
        logN = log((double) n);
        nthAproximation = (int) n * (logN + log(logN));
    } else {
        nthAproximation = 6;
    }

    numbers = malloc(sizeof(int)*nthAproximation);

    /*fill the array with natural numbers*/
    for (i=0;i<nthAproximation;i++){
        numbers[i]=i+2;
    }

    /*sieve the non-primes and count to the nth prime*/
    for (i=0;i<nthAproximation;i++){
        if (numbers[i]!=-1){
            count++;
            if(count == n){
                lastPrime = numbers[i];
            }
            for (j=2*numbers[i]-2;j<nthAproximation;j+=numbers[i])
                numbers[j]=-1;
        }
    }

    printf("%d\n",lastPrime);

return 0;
}