#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {

    if (argc <=1) {
        fprintf(stderr, "Eingabefehler aufgetreten, bitte geben Sie mind 1 Argument ein.");
        exit(1);

    }
    FILE *products;

    products = fopen("products.txt", "r");
    if (products==NULL){
        fprintf(stderr,"Lesefehler");
        exit(1);

    }

    struct produkte {
        char art[64];
        char markt[64];
        float kilo;
        float preis;
        float kilopreis;

    } produkte[50];
    char buffer[1000];
    int i = 0;

    while (fgets(buffer, 1000, products)!=NULL) {

        sscanf(buffer, "%63[^;];%63[^;];%f;%f", produkte[i].art, produkte[i].markt, &produkte[i].kilo,
               &produkte[i].preis);
        //printf("%s %s %f %f\n",produkte[i].art,produkte[i].markt,produkte[i].kilo,produkte[i].preis);
        produkte[i].kilopreis = produkte[i].preis / produkte[i].kilo;
        i++;
    }
    /*int j = 0;
    while (j < 36) {
        printf("%s %s %f %f %f pro Kilo\n", produkte[j].art, produkte[j].markt, produkte[j].kilo, produkte[j].preis,
               produkte[j].kilopreis);
        j++;
    }*/
    int temp = -1;
    for (int p=1;p<argc;p++) {
        char *artikel = argv[p];
    int i = 0;
    for (i = 0; i < 36; i++) {
        if (strcmp(artikel, produkte[i].art) == 0) {
            if (temp < 0) {
                temp = i;
            } else if (produkte[i].kilopreis <= produkte[temp].kilopreis) {
                temp = i;
            }

        }

    }
    if(temp>-1) {
        printf("%s: %.2f /kg, %s\n", artikel, produkte[temp].kilopreis, produkte[temp].markt);
        temp=-1;
    }
    else if(temp<0){
        printf("Produkt '%s' nicht gefunden\n",artikel);
    }
}
    fclose(products);
    return 0;
}