#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char vorname[20];
    char nachname[20];
    int alter;
    struct {
        char hobby1[20];
        char hobby2[20];
        char hobby3[20];
        char hobby4[20];
        char hobby5[20];
    } hobbies;
} person;

int main(void){
    FILE *datei = fopen("C:\\Programming_Workspace\\C_Programme_MSE_I\\UZ_4\\2_persons\\persons_input.txt", "r");
    //Jupyter: FILE *datei = fopen("persons_input.txt", "r");
    // FILE *datei2 = fopen("persons_output.txt", "w");

    if (datei == NULL) {
        // perror gibt die übergebene Fehlermeldung auf stderr aus, 
        // und hängt zusätzlich noch einen String dran, der die Fehlerursache beschreibt
        perror("Fehler: Konnte Datei nicht öffnen");
        return 1;
    }
/*         if (datei2 == NULL) {
        // perror gibt die übergebene Fehlermeldung auf stderr aus, 
        // und hängt zusätzlich noch einen String dran, der die Fehlerursache beschreibt
        perror("Fehler: Konnte Datei nicht öffnen");
        return 1;
    } */

    char buffer[256];
    person mypeople[20];
    int counter = 0;
    while (fgets(buffer, sizeof(buffer), datei) != NULL) {
        // sscanf(buffer,"%s;%s;%n;%s,%s,%s,%s,%s",mypeople[counter].vorname,mypeople[counter].nachname,&mypeople[counter].alter,mypeople[counter].hobbies.hobby1,mypeople[counter].hobbies.hobby2,mypeople[counter].hobbies.hobby3,mypeople[counter].hobbies.hobby4,mypeople[counter].hobbies.hobby5);
        sscanf(buffer,"%19[^;];%19[^;];%d;%19[^,],%19[^,],%19[^,],%19[^,],%19[^\n]",mypeople[counter].vorname,mypeople[counter].nachname,&mypeople[counter].alter,mypeople[counter].hobbies.hobby1,mypeople[counter].hobbies.hobby2,mypeople[counter].hobbies.hobby3,mypeople[counter].hobbies.hobby4,mypeople[counter].hobbies.hobby5);
        // sscanf(buffer,"%19[^;];%19[^;];%n;%19[^,],%19[^,],%19[^,],%19[^,],%19[^,]",mypeople[counter].vorname,mypeople[counter].nachname,&mypeople[counter].alter,mypeople[counter].hobbies.hobby1,mypeople[counter].hobbies.hobby2);
        // sscanf(buffer,"%s;%s;%n;%s",mypeople[counter].vorname,mypeople[counter].nachname,&mypeople[counter].alter,mypeople[counter].hobbies.hobby1);
        // fprintf(datei2,"%s-%s-%d-%s--%s--%s--%s--%s\n",mypeople[counter].vorname,mypeople[counter].nachname,mypeople[counter].alter,mypeople[counter].hobbies.hobby1,mypeople[counter].hobbies.hobby2,mypeople[counter].hobbies.hobby3,mypeople[counter].hobbies.hobby4,mypeople[counter].hobbies.hobby5);
        counter++;
        if(counter>20){
            break;
        }
    }

    for(counter=0;counter<20;counter++){
        if(mypeople[counter].alter>20 && mypeople[counter].alter<=30){
            char* tanz = "Tanzen";
            char* tanz2 = "Tanzen\n";
            if(strcmp(mypeople[counter].hobbies.hobby1,tanz)==0||strcmp(mypeople[counter].hobbies.hobby1,tanz2)==0){
                printf("%s\n",mypeople[counter].nachname);
            } else if(strcmp(mypeople[counter].hobbies.hobby2,tanz)==0||strcmp(mypeople[counter].hobbies.hobby2,tanz2)==0){
                printf("%s\n",mypeople[counter].nachname);
            } else if(strcmp(mypeople[counter].hobbies.hobby3,tanz)==0||strcmp(mypeople[counter].hobbies.hobby3,tanz2)==0){
                printf("%s\n",mypeople[counter].nachname);
            } else if(strcmp(mypeople[counter].hobbies.hobby4,tanz)==0||strcmp(mypeople[counter].hobbies.hobby4,tanz2)==0){
                printf("%s\n",mypeople[counter].nachname);
            } else if(strcmp(mypeople[counter].hobbies.hobby5,tanz)==0||strcmp(mypeople[counter].hobbies.hobby5,tanz2)==0){
                printf("%s\n",mypeople[counter].nachname);
            }
        }
    }

    fflush(datei);
    // fflush(datei2);
    fclose(datei);
    // fclose(datei2);

    return 0;
}