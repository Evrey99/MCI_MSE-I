#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int average(float* average_output, int* inputs_pointer, int array_size);
int variance(float* variance_inoutput, float* average_value, int* inputs_pointer, int array_size);

int main(void){

    printf("Geben Sie die Anzahl der Elemente Ihres Arrays an:\n");

    int read_size_array;
    scanf("%i", &read_size_array);
    // read_size_array = 3;

    const int size_array = read_size_array;

    int inputs_pointer[size_array];
    for (int i = 0; i < size_array; i++) {
        printf("Geben Sie das %d. Element an:\n", i+1);
        scanf("%d", &inputs_pointer[i]);
        // inputs_pointer[i] = (i)*2;
    }

    float average_value;
    float variance_value;
    
    average(&average_value, inputs_pointer, size_array);
    variance(&variance_value, &average_value, inputs_pointer, size_array);

    printf("Der Mittelwert Ihres Arrays ist: %f\n",average_value);
    printf("Die Varianz Ihres Arrays ist: %f\n",variance_value);
    
    return EXIT_SUCCESS;

}

int average(float* average_inoutput, int* inputs_pointer, int array_size){
        //adresse von Output variable übernehmen und darf verändert werden
        //andresse von inputs pointer und größe übernehmen, darf nicht veränder werden, aber dadurch kennen wir die daten
    int sum = 0;
    for (int i = 0; i < array_size; i++) {
        sum += inputs_pointer[i];
    }

    *average_inoutput = (sum/array_size);
    return EXIT_SUCCESS;
}

int variance(float* variance_inoutput, float* average_value, int* inputs_pointer, int array_size){
        //ähnlich wie bei kommentar bei average, nur dass ich auch wissen muss wo der durchschnitt liegt.
    float sum = 0;
    for (int i = 0; i < array_size; i++) {
        sum += pow((inputs_pointer[i]-*average_value),2);
    }

    *variance_inoutput = (sum/array_size);
    return EXIT_SUCCESS;
}