/*
 * is_odd.c
 *
 *  Created on: 01.12.2021
 *      Author: Klaus
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

	if (argc==1||argc>=3){
		printf("false\n");
		return 0;
	} else {
		char* a = argv[1];
		int x = atoi(a);

		if (x%2 == 0){
			printf("false\n");
		} else {
			printf("true\n");
		}
	}
	return 0;
}
