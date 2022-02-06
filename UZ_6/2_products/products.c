#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 0
#define DEBUG_PRINT_1 0
#define STRINGIZE 64
#define BUF_SIZE 1024
#define ROWS 36

#if DEBUG
    #define number_o_prod 3
#endif

typedef struct {
    char product_name[STRINGIZE];
    char store_name[STRINGIZE];
    float price_p_kg;
} product_struct;

void read_products(const int product_count, product_struct *products){
    char curr_product_name[STRINGIZE];
    char curr_store_name[STRINGIZE];
    float curr_kg;
    float curr_price;
    float curr_price_p_kg;
    char buffer[BUF_SIZE];

    FILE * datei = fopen("products.txt", "r");

    int count = 0;
    while((fgets(buffer,sizeof(buffer),datei)!=NULL) && (count < ROWS)){
        sscanf(buffer, "%[^;];%[^;];%f;%f\n",\
            curr_product_name,\
            curr_store_name,\
            &curr_kg,\
            &curr_price);
        curr_price_p_kg = (float)curr_price/(float)curr_kg;
        for(int x = 0; x < product_count; x++){
            if ( strcmp(curr_product_name, products[x].product_name) == 0 ){
                if ( products[x].price_p_kg > curr_price_p_kg || products[x].price_p_kg == 0){
                    strcpy(products[x].store_name,curr_store_name);
                    products[x].price_p_kg = curr_price_p_kg;
                }
            }
        }
    }

    fclose(datei);

}

void print_products(const int product_count, product_struct *products){
    for (int x = 0; x < product_count; x++){
        if( products[x].price_p_kg == 0){
            printf("Produkt '%s' nicht gefunden\n",\
                products[x].product_name);
        } else {
            printf("%s: %.2f €/kg, %s\n",\
                products[x].product_name,\
                products[x].price_p_kg,\
                products[x].store_name);
        }
    }
}

int main(const int argc, char **argv){
    
    #if DEBUG
    product_struct products[number_o_prod];
    char products_test[number_o_prod][STRINGIZE] = {"Milch", "Sahne", "Eier"};
    for(int i=0; i < argc -1; i++){
        strcpy(products[i].product_name,products_test[i]);
        products[i].price_p_kg = 0;
    }
    #else
    if (argc <= 1){
        fprintf(stderr, "Eingabefehler\n");
        return EXIT_FAILURE;
    }
    const int number_o_prod = argc -1;
    product_struct products[number_o_prod];
    for (int i = 0; i < argc-1; i++) {
        strcpy(products[i].product_name, argv[i+1]);
        products[i].price_p_kg = 0;
    }   
    #endif

    #if DEBUG_PRINT_1
    for (int i = 0; i < number_o_prod; i++){
        printf("Product %s\n", products[i].product_name);
    }
    #endif

    read_products(number_o_prod, products);
    print_products(number_o_prod, products);
}
