// stdio.h muss eingebunden werden, damit in Dateien geschrieben werden kann
#include <stdio.h>

int main() {
    // Zuerst müssen wir eine neue Datei anlegen
    FILE *datei = fopen("integers_output.txt", "w"); //interessant ist mit a zu testen

    // IMMER überprüfen, ob die Datei auch wirklich angelegt wurde
    // Wenn bei fopen ein Fehler passiert ist, dann wird ein Null-Pointer zurückgegeben
    if (datei == NULL) {
        // perror gibt die übergebene Fehlermeldung auf stderr aus,
        // und hängt zusätzlich noch einen String dran, der die Fehlerursache beschreibt
        perror("Fehler: Konnte Datei nicht anlegen");
        return 1;
    }
    char buffer[256];
while (*(fgets(buffer, sizeof(buffer), stdin)) != '\n') {
        char *pointer = buffer;
        int check = 1;
        int count = 0;
        while(*pointer != '\n'){
            int number;
            if((sscanf(pointer, "%d", &number) == 1) && check){
                if(count > 0){fprintf(datei," ");}
                fprintf(datei,"%d", number);
                count++;
                check = 0;
            } else if ((sscanf(pointer, "%d", &number) == 0) && !check){
                check = 1;
            }
            pointer++;
        }
        fprintf(datei,"\n");

    }

    // Streams sind gebuffert, daher kann es passieren, dass nicht der ganze Text in der Datei landet
    // Mit fflush können wir erzwingen, dass der Buffer geleert wird.
    fflush(datei);

    // IMMER die Datei wieder schließen, wenn sie nicht mehr gebraucht wird.
    fclose(datei);

    return 0;
}