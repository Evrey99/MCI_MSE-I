/*
 * powerof2.c
 *
 *  Created on: 02.12.2021
 *      Author: Klaus
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[]){

	if (argc==1||argc>=3){
		return 0;
	} else {
		char* a = argv[1];
		int x = atoi(a);
		//printf("%d\n",x);
		for (int i = 0; pow(2, i) < x+1; i++){
			//printf("%d\n",i);
			//printf("%f\n",pow(2,i));
			if (pow(2,i) == x){
				printf("%d\n",i);
				return 0;
			}
		}
	}
	return 0;
}
