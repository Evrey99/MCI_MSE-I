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

float operation(int num_one, int num_two, char operator){
	if (operator == '+'){
		return addition(num_one, num_two);
	} else if (operator == '-'){
		return subtraction(num_one, num_two);
	} else if (operator == '/'){
		return division(num_one, num_two);
	} else if (operator == '*'){
		return multiplication(num_one, num_two);
	} else {
		return EXIT_FAILURE;
	}
}

int addition(int num_one, int num_two){
	return (num_one + num_two);
}
int subtraction(int num_one, int num_two){
	return (num_one - num_two);
}
float division(int num_one, int num_two){
	if (num_two == 0){
		printf("der Divisor darf nicht 0 sein!");
		return EXIT_FAILURE;
	}
	return ((float)num_one / (float)num_two);
}
int multiplication(int num_one, int num_two){
	return (num_one * num_two);
}
