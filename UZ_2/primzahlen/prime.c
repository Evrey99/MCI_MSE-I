/*
 * prim.c
 *
 *  Created on: 12.12.2021
 *      Author: Klaus
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isprime(int number){
	if((number % 2 == 0 || number < 2) && number != 2){
		return 0;
	}
	for(int i = 3; i <= pow(number,0.5) + 1 ; i+=2){
		if(number % i == 0){
			return 0;
		}
	}
	return 1;
}

int main(int argc, char **argv){
	if (argc != 2){
		return EXIT_FAILURE;
		
	}
	int maxnumber = atoi(argv[1]);
	int count = 0;

	if(maxnumber < 2){
		return EXIT_FAILURE;
	} else {
		printf("%d\t",2);
		count++;
	}
	for (int i = 3; i <= maxnumber; i+=2) {
		if (isprime(i) == 1){
			if (count == 9) {
				printf("%d\n",i);
				count = 0;
			} else {
				printf("%d\t",i);
				count++;
			}
		}
	}
	return EXIT_SUCCESS;
}

