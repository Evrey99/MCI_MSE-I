#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    if (argc != 1){
        return  EXIT_FAILURE;
    }

    // printf("please enter a String:\n");
    fflush(stdout);

    char entered_string[51];
    int maxsize = sizeof(entered_string)-1;
    // printf("größe des strings: %d\n", maxsize);
    scanf("%[^\n]", entered_string);
        for (int i = 0; i < maxsize; i++){
            if (entered_string[i] >= 'a' && entered_string[i] <= 'z'){
                entered_string[i] = entered_string[i] - 32;
            }
        }
    printf("%s\n",entered_string);

}