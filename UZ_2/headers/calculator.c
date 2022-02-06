/*
 * operations.c
 *
 *  Created on: 11.12.2021
 *      Author: Klaus
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operations.h"

int main(int argc, char *argv[]) {

	int c = argc;
	printf("%d\n",argc);

	while(c-- >0)	{
		printf("%s\n",argv[c]);
	}
	
	if (argc != 4){
		return EXIT_FAILURE;
	}
	int num_one = atoi(argv[1]);
	int num_two = atoi(argv[3]);
	char* operator = argv[2];

	if (strcmp(operator, "/") == 0){
		printf("%f",operation(num_one,num_two,operator));
	} else {
		printf("%d",(int)operation(num_one,num_two,operator));
	}
	return EXIT_SUCCESS;
}
