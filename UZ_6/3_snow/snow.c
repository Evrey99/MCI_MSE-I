#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_LEN 64 //Standardgröße für Strings bzw char Arrays
#define DEBUG_PRINT_1 0 //für Präprozessor if Formeln, damit ich für die finale Kompilierung nichts löschen muss
#define DEBUG_PATH 0 //für Präprozessor if Formeln, damit ich zum Debuggen andere Varianten testen kann
#define BUFFER_SIZE 256 //Standardgröße für fgets Buffer
#define PATH_SIZE 512 //Standardgröße für char Arrays von Dateipfaden
#define WINDOWS_PATH 1 //für Präprozessor if Formeln, damit man feststellen kann, dass man 
#define LINUX_PATH 1 //kann technisch immer auf true sein, weil in if/elif eingebaut

//Struct um alle meine Inputs zurück geben zu können
typedef struct {
    char city[STRING_LEN];
    int num_o_days;
} curr_city;

//Funktion um Inputs vom User entgegenzunehmen
curr_city* find_inputs(){
    //Speicher und Variablen allokieren
    curr_city * input = malloc(sizeof(curr_city));
    char buf[STRING_LEN];

    //Inputs anfordern und entgegennehmen
    printf("Geben Sie einen Ort an:\n");
    fflush(stdout);
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%s\n", input->city);
    printf("Geben Sie einen Tag an:\n");
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d\n", &input->num_o_days);

    //Eingabeüberprüfung des Tages
    if(input->num_o_days < 1 || input->num_o_days > 8||buf[1] != '\n'){
        fprintf(stderr, "Eingabefehler");
        exit(1);
    }

    return input;
}

//Funktion um alle Files zu finden, durch diese zu iterieren und die gesuchten Daten in ein Output-File zu schreiben
void iterate_files(int max_day, char * input_city){
    // Pointer auf Output File, welches ich für die gesamte Funktion benötige
    FILE * output_file = NULL;
    // Variable für die Summe aller Schneetage
    int snow_sum;
    //Loop durch alle Input Files bis zum eingegebenen Tag, i ist dabei auch der aktuelle Filename
    for(int i = 0; i < max_day; i++){

        //Variablen für den Pfad und Basis-Pfad festlegen, über Präprozessor kann vor dem kompilieren zwischen einem relativen und absoluten Pfad getauscht werden
        char current_total_path[PATH_SIZE];
        char output_path[PATH_SIZE];
        #if WINDOWS_PATH
            #if DEBUG_PATH 
            char base_path[] = "C:\\Programming_Workspace\\C_Programme_MSE_I\\UZ_6\\3_snow\\snow_data\\";
            #else 
            char base_path[] = ".\\snow_data\\";
            #endif
        #elif LINUX_PATH
            char base_path[] = "snow_data/";
        #endif

        //hier werden die Namen der Pfade erstellt, über sprintf werden die wird der Basispfad mit den Filenamen zusammengefügt und das aktuelle Input-File geöffnet
        sprintf(current_total_path, "%s%d.txt",base_path,i+1);
        sprintf(output_path, "%s%s_%d.txt", base_path,input_city, max_day);
        FILE * input_file = fopen(current_total_path,"r");

        //Überprüfung ob das Inputfile geöffnet werden konnte
        if(input_file == NULL){
            perror("Lesefehler, File konnte nicht geöffnet werden\n");
            exit(1);
        }

        //buffer für fgets und true/false Variable erstellen
           //zweitere um außerhalb der while Schleife feststellen zu können, ob die aktuelle for Schleife beendet werden kann, wenn die Stadt in den Files nicht existiert 
        char buf[BUFFER_SIZE];
        short found_city = 0;

        //File wird zeilenweise eingelesen und in zwei temporären Variablen gespeichert
        while(fgets(buf, sizeof(buf), input_file)!=NULL){
            char curr_city[STRING_LEN];
            int curr_snow;
            sscanf(buf, "%[^;];%d\n", curr_city, &curr_snow);

            //wenn die aktuell eingelesene Zeile gleich der eingegebenen Stadt ist, wird das Output-File erstellt bzw. befüllt
            if(strcmp(curr_city, input_city)==0){
                found_city = 1;

                //in der ersten Iteration wird zuerst noch der File Pointer richtig gesetzt und überprüft ob dies auch funktioniert hat
                if(i==0){
                    output_file = fopen(output_path,"w");

                    if(output_file == NULL){
                        perror("Schreibfehler, File konnte nicht erstellt werden\n");
                    }
                    
                //wurde das File erfolgreich geöffnet oder sind wir in der zweiten Iteration, schreiben wir in die Output Datei.
                    fprintf(output_file,"Tag %d: %d\n", i+1, curr_snow);
                } else {
                    fprintf(output_file,"Tag %d: %d\n", i+1, curr_snow);
                }

                //der Wert des aktuellen Ortes wird aufaddiert und die while schleife verlassen
                snow_sum += curr_snow;
                break;

            }
        
        }
        //abbrechen, wenn die Stadt nicht gefunden wurde
        if(!found_city){
            fprintf(stderr, "Ort wurde nicht gefunden!\n");
            break;
        }


        //am Ende jeder Iteration wird das aktuelle Input File geschlossen
        fclose(input_file);
    }
    //am Ende aller Iterationen schreiben wir die Gesamtsumme ins Output file und schließen dieses 
    fprintf(output_file, "Summe: %d", snow_sum);
    fclose(output_file);
}

int main(void){
    
    //aufruf der Eingabe Funktion
   curr_city* input = find_inputs();

    //debug Argument um Eingabefunktion zu testen
    #if DEBUG_PRINT_1
    printf("Ort: %s, Tag: %d", input->city, input->num_o_days);
    #endif

    //aufruf der Funktion, welche die Files auslesen soll und ein Output File erstellen
    iterate_files(input->num_o_days, input->city);

    return EXIT_SUCCESS;
}