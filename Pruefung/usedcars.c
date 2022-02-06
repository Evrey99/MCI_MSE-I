#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_INPUT_ROWS 42
#define STRING_LEN 64
#define NUM_O_EQUIP 6 //maximale Anzahl an Zusatzaustattungen
#define BUFFER_SIZE 256

typedef struct {
    char brand[STRING_LEN]; //Marke
    char model[STRING_LEN]; //Modell
    int year_prod; //Baujahr
    int driven_km; //Kilometerstand
    float price; //Verkaufspreis
    char extra_equip[NUM_O_EQUIP][STRING_LEN]; //Zusatzaustattungen
} used_cars_t;

used_cars_t used_cars_list[MAX_INPUT_ROWS];

int read_used_cars_file(){ //Rückgabewert ist die Anzahl der eingelesenen Autos, damit man für die darauffolgende Funktionen effizienter damit arbeiten kann
    FILE * file_used_cars = fopen("gebrauchtwagen.csv","r");

    if(file_used_cars == NULL){
        perror("Lesefehler, File kann nicht geöffnet werden");
    }

    char buffer[BUFFER_SIZE];
    int count_rows = 0;

    //Zeile wird eingelesen und über sscanf zerlegt, für die lesbarkeit in mehr Zeilen geschrieben
    while((fgets(buffer, sizeof(buffer), file_used_cars)!=NULL)&&(count_rows <= MAX_INPUT_ROWS)){
        sscanf(buffer, "%63[^:]:%63[^:]:%d:%d:%f:%63[^#\n]#%63[^#\n]#%63[^#\n]#%63[^#\n]#%63[^#\n]#%63[^#\n]\n", \
                used_cars_list[count_rows].brand,\
                used_cars_list[count_rows].model,\
                &used_cars_list[count_rows].year_prod,\
                &used_cars_list[count_rows].driven_km,\
                &used_cars_list[count_rows].price,\
                used_cars_list[count_rows].extra_equip[0],\
                used_cars_list[count_rows].extra_equip[1],\
                used_cars_list[count_rows].extra_equip[2],\
                used_cars_list[count_rows].extra_equip[3],\
                used_cars_list[count_rows].extra_equip[4],\
                used_cars_list[count_rows].extra_equip[5]);

        count_rows++;
    }

    fclose(file_used_cars);
    return count_rows;

}

int main(int argc, char **argv){
    
    if (argc < 3){
        fprintf(stderr,"Eingabefehler, es wurden zu wenig Argumente (%d statt min. 3) mitgegeben", argc);
        return EXIT_FAILURE;
    }

    for(int i = 0; i < strlen(argv[1]); i++){ 
        if(isdigit((unsigned char)argv[1][i])==0){
            fprintf(stderr,"Eingabefehler, kein korrektes Jahr eingegeben");
            return EXIT_FAILURE;
        }
    }

    for(int i = 0; i < strlen(argv[2]); i++){ 
        if(isdigit((unsigned char)argv[2][i])==0&&argv[2][i] != '.'){
            fprintf(stderr,"Eingabefehler, keinen korrekten Preis pro Kilometer eingegeben");
            return EXIT_FAILURE;
        }
    }

    int i_year_car_prod = atoi(argv[1]); //Baujahr des Eingabearguments, i_ für Input
    
    if(i_year_car_prod < 0){
        fprintf(stderr,"Eingabefehler, Jahr im Minusbereich");
        return EXIT_FAILURE;
    }
    
    float i_price_p_km = atof(argv[2]); //Input Preis pro km

    char i_extra_equip[NUM_O_EQUIP][STRING_LEN]; //Input für Extra Equip

    int num_of_extra_equip = argc - 3;

    if(argc >= 4){
        for(int i = 0; i < argc -3; i++){
            strcpy(i_extra_equip[i],argv[i+3]);
        }
    }

    //ruft die Funktion auf, welche das File einliest und die Werte in einem globalen Struct ausliest, gibt die Anzahl der eingelesenen Autos zurück (falls das File kleiner ist)
    int num_readable_cars = read_used_cars_file();
    
    //bei dem letzten Auto wird angefangen zu schauen ob die parameter zutreffen
    for(int i = num_readable_cars; i >= 0; i--){
        //eine Zähl variable um den Rückgabewert des darunterliegenden Loops zu testen, hätte gern eine separate Funktion hierfür gehabt, aber der char** pointer hat nicht funktioniert
        int found_num_of_extra_equip = 0;
        //loop durch alle eingegebenen Zusatzaustattungen
        for( int x = 0; x < num_of_extra_equip;x++){
            int found_equip = 0;
            //loop durch alle Zusatzaustattungen des aktuellen Autos aus der gebrauchtwagen.csv, wenn gefunden, wird die true false Variable found_equip auf wahr gestellt
            for(int j = 0; j<NUM_O_EQUIP;j++){
                if(strcmp(used_cars_list[i].extra_equip[j],i_extra_equip[x])==0){
                    found_equip = 1;
                }
            }
            //wenn das equipment nicht gefunden wurde, wird der loop abgebrochen
            if(!found_equip){
                break;
            } else {
                found_num_of_extra_equip += 1;
            }
        }
        //wenn alle Equipments gefunden wurden und die anderen Parameter übereinstimmen wird das Auto in die Konsole geschrieben
        if ( found_num_of_extra_equip == num_of_extra_equip && used_cars_list[i].year_prod>=i_year_car_prod && (used_cars_list[i].price/used_cars_list[i].driven_km)<=i_price_p_km){

            printf("%s %s, Baujahr %d, Kilometerstand: %d km, Preis: %.2f Euro\n\tZusatzaustattung: ",\
                used_cars_list[i].brand,\
                used_cars_list[i].model,\
                used_cars_list[i].year_prod,\
                used_cars_list[i].driven_km,\
                used_cars_list[i].price);
            int x = 0;
            while(1){ //hier loopen wir so lange bis wir alle Equipments eines jeden Autos durchgeschaut haben
                printf("%s", used_cars_list[i].extra_equip[x]);
                if(x + 1 < NUM_O_EQUIP && strlen(used_cars_list[i].extra_equip[x+1])>0){ //wenn der nächste string nicht leer ist und der nächste überhaupt noch in der Liste sein kann wird ein Beistrich gedruckt
                    printf(", ");
                }
            x++;
            if(x>=NUM_O_EQUIP) break;
            }
            printf("\n");
        }
    }
    return EXIT_SUCCESS;
}