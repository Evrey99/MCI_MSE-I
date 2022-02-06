/*
 * operations.c
 *
 *  Created on: 11.12.2021
 *      Author: Klaus
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "operations.h"

int main() {

	char buffer[256];
	int position = 1;
	char operator;
	int num[2];
	while (1) {
		if(position == 1){
			printf("Geben Sie die Zahl 1 ein:\n");
			fflush(stdout);
			fgets(buffer, sizeof(buffer), stdin);
			int i = 0;
			if(strcmp(buffer, "exit\n")==0){
				printf("Rechner wird geschlossen!");
				break;
			}
			while(buffer[i]){
				if(!isdigit(*buffer+i)){
					printf("Falsche Eingabe!\n");
					fflush(stdout);
					position = 1;
					break;
				}
				i++;
			}
			// printf("Eingabe erfolgreich!\n");
			position++;
			num[0]=atoi(buffer);
		} else if (position == 2) {
			printf("Geben Sie die Operation ein:\n");
			fflush(stdout);
			fgets(buffer, sizeof(buffer), stdin);
			if(buffer[1] =='\n'&&buffer[2] =='\0'){
				// printf("Richtiger Zweig!\n");
				if(buffer[0] == '+'||buffer[0] == '-'||buffer[0] == '*'||buffer[0] == '/'){
					operator = buffer[0];
					// printf("Richtige Eingabe!\n");
				} else {
					printf("Falsche Eingabe!\n");
					position = 1;
					continue;
				}
			} else if (strcmp(buffer, "exit\n")==0) {
				printf("Rechner wird geschlossen!");
				break;
			} else {
				printf("Falsche Eingabe!\n");
				position = 1;
				continue;
			}
			position++;
		} else if (position == 3){
			printf("Geben Sie die Zahl 2 ein:\n");
			fgets(buffer, sizeof(buffer), stdin);
			
			if(strcmp(buffer, "exit\n")==0){
				printf("Rechner wird geschlossen!");
				break;
			}
			int i = 0;
			while(buffer[i]){
				if(!isdigit(*buffer+i)){
					printf("Falsche Eingabe!\n");
					fflush(stdout);
					position = 1;
					break;
				}
				i++;
			}
			// printf("Eingabe erfolgreich!\n");
			num[1]=atoi(buffer);
			// printf("%d %d %c", num[0], num[1],operator);
			printf("Ergebnis: %f\n",operation(num[0],num[1],operator));
			num[0]=0;num[1]=0;position=1;
		}				
	}
	return EXIT_SUCCESS;
}
