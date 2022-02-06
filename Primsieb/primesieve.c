#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]){

    if (argc != 2){
        return EXIT_FAILURE;
    }

    long upperbound = atol(argv[1]);
    long primes_bool[upperbound];

    for (long i = 0; i <= upperbound; i++)
    {
        primes_bool[i] = 1;
    }

    primes_bool[0] = 0;
    primes_bool[1] = 0;

    for (long i = 4; i <= upperbound; i+=2)
    {
        primes_bool[i] = 0;
    }

    long limit = sqrt(upperbound) + 1;

    for (long i = 3; i < limit; i+=2)
    {
        if (primes_bool[i]) {
            for (long j = i*i; j <= upperbound; j+=i)
            {
                primes_bool[j] = 0;
            }
        }
    }
    long count = 0;
    for (long i = 0; i <= upperbound; i++)
    {
        if (primes_bool[i] && count == 9){
            printf("%ld\n",i);
            count = 0;
        } else if (primes_bool[i]){
            printf("%ld\t",i);
            count++;
        }
    }

    return 0;

}
