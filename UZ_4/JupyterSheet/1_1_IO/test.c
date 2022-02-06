#include <stdio.h>

int main() {
    // scanf liest von stdin
    int number;
    printf("Geben Sie eine Zahl ein: ");
    scanf("%d", &number);
    
    // Mit fscanf können wir den Stream angeben, von dem gelesen werden soll.
    // Hier lesen wir wieder eine Zahl aus stdin
    printf("Geben Sie eine Zahl ein: ");
    fscanf(stdin, "%d", &number);
    
    return 0;
}