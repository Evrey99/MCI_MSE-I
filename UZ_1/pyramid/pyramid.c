/*
 * pyramid.c
 *
 *  Created on: 01.12.2021
 *      Author: Klaus
 */
#include <stdio.h>
int main(){
	for (int i = 1; i<6; i += 2){
		int check = (5-i)/2;
		for (int x = 1; x <6; x++){
			if(x <= check){
				printf(" ");
			} else if (x-5 > check*-1){
				printf(" ");
			} else {
				printf("*");
			}

		}
		printf("\n");
	}
}
