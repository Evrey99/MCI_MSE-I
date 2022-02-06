#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXArraySize ((int)5)

int average(float* average_output, int* inputs_pointer, int array_size);

int main(void){

    int multiple = 1;
    int* myarray = (int*) malloc((multiple * MAXArraySize) * sizeof(int));
    int count = 1;
    char buffer[256];

    fprintf(stdout, "Geben Sie die Elemente Ihres Arrays an:\n");
    while(1){
        if (count == (multiple * MAXArraySize)){
            myarray = (int*) realloc(myarray, multiple * MAXArraySize * sizeof(int));
        }

        fprintf(stdout, "Element #%d: ", count);
        fflush(stdout);
        fgets(buffer, sizeof(buffer), stdin);
        if (buffer[0]=='\n' && buffer[1]=='\0'){
            count--;
            break;
        } {
            int i = 0;
            int x = 0;
            for (i = 0; i < strlen(buffer); i++){ 
                if(!(isdigit(*buffer+i))) {
                    x = 1;
                    break;
                }
            }
            if (x){
                continue;
            }
        }

        sscanf(buffer, "%d", &myarray[count-1]);

        count++;
    }
    fprintf(stdout, "Eingabe beendet.\n");
    //average
    float average_value;
    average(&average_value, myarray, count);
    printf("Der Durchschnitt Ihres Arrays ist: %.2f\n",average_value);
    //printf("Die Größe Ihres Arrays ist: %d\n",count);
    
    free(myarray);

    return EXIT_SUCCESS;
}

int average(float* average_inoutput, int* inputs_pointer, int array_size){
        //adresse von Output variable übernehmen und darf verändert werden
        //andresse von inputs pointer und größe übernehmen, darf nicht veränder werden, aber dadurch kennen wir die daten
    int sum = 0;
    for (int i = 0; i < array_size; i++) {
        sum += inputs_pointer[i];
    }

    *average_inoutput = ((float)sum/(float)array_size);
    // fprintf(stdout,"Wert des Durchschnitts %f\n",*average_inoutput);
    return EXIT_SUCCESS;
}
