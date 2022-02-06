#include <stdlib.h>
#include <stdio.h>

int * get_array()
{
    //Initialisierung der Array-Größe, eines Pointers für das Array selbst, sowie die Zählervariable "i"
    int n = 0;
    int i;

    //Funktion, zur Eingabe und damit Definition der Array-Größe in Form einer Ganzzahl-Eingabe per Tastatur
    printf("Geben Sie die Anzahl der Elemente Ihres Arrays an: \n");
    fflush(stdout);
    scanf("%d", &n);
    fflush(stdout);
    //printf("Gewünschte Anzahl der Elemente: %d.\n", n);

    //Funktion, welche den notwendigen Speicherplatz für das Array "reserviert"
    //array = (int*)malloc(n * sizeof(int));

    //Funktion, welches ein Array mit Größe "n" aka "const int x" initialisiert
    const int x = n;
    int array[x];

    //Basierend auf der eingegebenen Array-Größe werden n-mal Eingabewerte abgefragt
    for(i = 0; i < x; i++)
    {
        printf("Die %d. Zahl lautet: \n", i+1);
        fflush(stdout);
        scanf("%d", &array[i]);
        fflush(stdout);
    }

    /* PRINTF-Funktion zur Prüfung der Eingabewerte
    printf("Die eingegebenen Werte lauten: \n");
    for(i = 0; i < x; i++)
    {
        printf("%d\n", array[i]);
    }
    */

    //Mithilfe eines Pointers wird das Array und dessen Inhalte nun als Rückgabewert dieser Funktion weiterverwendet
    return array;
}

/* TO DO - MITTELWERT
int * mittelwert()
{
    int summe = 0;
    int m_result = 0;
    int *array;
    int i;
    
    array = get_array();

    for(i = 0; i < (sizeof(array)/sizeof(int)); i++)
    {
        summe = summe + array[i];  
    }

    m_result = summe/(sizeof(array)/sizeof(int));
    
    return m_result;
}
*/

/* TO DO - VARIANZ
int * varianz()
{

}
*/

int main(void) //TEST-FUNKTION - muss noch geändert werden; Basis is MITTELWERT-Funktion
{
    int i;
    int *array;
    int summe = 0;
    int final_summe = 0;

    array = get_array();
    printf("Die Größe des Arrays lautet: %lu.\n", (sizeof(array)));

    for(i = 0; i < (sizeof(&array)/sizeof((&array)[0])); i++)
    {
        summe = summe + array[i];
    }
    final_summe = summe / i;
    
    printf("Der Mittelwert lautet: %d\n", final_summe);

    return 0;
}

/*
int main(void)
{
    int *array;
    int i;
    int *m_result;

    array = get_array();

    for(i = 0; i <= (sizeof(array)/sizeof(int)); i++)
    {
        printf("%d", array[i]);
    }

    m_result = mittelwert();
    printf("%d", m_result);    

    return 0;
}
*/