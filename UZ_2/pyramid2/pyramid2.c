/*
 * pyramid2.c
 *
 *  Created on: 11.12.2021
 *      Author: Klaus
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	if (argc == 2) {
		int row_number = atoi(argv[1]);
		for (int i = 1; i <= row_number; i++) {
			if (row_number == 1){
				printf("*\n");
			}
			else {
				int row_width = row_number*2-1;
				int emptys = row_width - (2*i) + 1;
				int stars = row_width - emptys;
				int cur_no_stars = 0;
				int cur_no_emptys = 0;
				for (int x = 0; x < row_width;x++){

					if (i == row_number){
						printf("*");
					}
					else {

						if (cur_no_emptys < emptys/2){
							printf(" ");
							cur_no_emptys++;
						}
						else if (cur_no_stars < stars){
							printf("*");
							cur_no_stars++;
						}
					}

				}
				if (i != row_number){
					printf("\n");
				}
			}
		}
	}
	else {
		return 1;
	}
	return 0;
}

