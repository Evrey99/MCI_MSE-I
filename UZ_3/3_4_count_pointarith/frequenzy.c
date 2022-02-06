#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char* a, char* b);
void quicksort(char *begin, char *end);
int stringsize(int argc, char** argv);

int main(int argc, char* argv[]){
    if(argc < 2) {
        return EXIT_FAILURE;
    }

    const int c_stringsize = stringsize(argc, argv);

    printf("%d\n",c_stringsize);

    // const int _stringsize = strlen(argv[1]);
    // char debug_string[6];
    char new_string[c_stringsize];
    strcpy(new_string,*(argv+1));
    // strcpy(debug_string,argv[1]);

        for(int i = 1; i < argc - 1; i++){
            // strcpy(debug_string,argv[i+1]);
            // printf("%s\n",debug_string);
            char* leerzeichen = " ";
            strcat(new_string, leerzeichen);
            strcat(new_string, *(argv+i+1));
        }

    printf("string vor dem sortieren: %s...\n", new_string);
    quicksort(new_string, new_string+c_stringsize-2);
    printf("string nach dem sortieren: %s...\n", new_string);

    int count = 1;
    for (int i = 0; i < c_stringsize-1; i++){
        if(*(new_string+i)!=*(new_string+i+1)){
            printf("Zeichen: '%c' - Häufigkeit: %d\n",*(new_string+i),count);
            count = 1;
        } else {
            count ++;
        }
    }

    
    return EXIT_SUCCESS;
}

int stringsize(int argc, char** argv){
    int size = 0;
    for(int i = 1; i < argc; i++) {
        size += strlen(*(argv+i)) + 1;
        // printf("%s\n", argv[i]);
    }
    return size;
}

// Hilfsfunktion, die zwei Zahlen vertauscht
void swap(char* a, char* b) { 
    int temp = *a;
    *a = *b;
    *b = temp;
} 

/*
 * Diese Funktion implementiert den Quicksort Algorithmus.
 */
void quicksort(char *begin, char *end) {
    // Rekursionsanfang: Wenn Array aus weniger als 2 Elementen besteht, dann breche ab
    if (end - begin <= 1)
        return;
    
    // Wir nehmen das 2. Element vorläufig als Arrayteiler
    char *teiler = begin + 1;
    
    // Wir gehen das Teilarray von links nach rechts durch,
    // und vertauschen alle Elemente mit dem Arrayteiler,
    // die kleiner als das erste Element (=Pivotelement) sind.
    char *current = begin;
    while (++current <= end) {
        if (*current < *begin) {
            swap(current, teiler);
            teiler++;
        }
    }
    
    // Setze Pivotelement an die richtige Position
    swap(begin, teiler - 1);
    
    // Sortiere rekursiv die beiden Teilarrays.
    quicksort(begin, teiler - 1);
    quicksort(teiler, end); 
}