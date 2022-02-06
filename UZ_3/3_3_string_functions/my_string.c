#include <stdio.h>
#include <stdlib.h>


int string_cmp(const char* str1, const char* str2){
    int i = 0;
        while (*(str1+i)!='\0' || *(str2+i)!='\0'){
            if (*(str1+i)!=*(str2+i)){
                return 0;
            }
            i++;
        }
    return 1;    
}
unsigned int string_len(const char* str){
    int i = 0;
    while (*(str+i)!='\0'){
        i++;
    }
    return i;
}
void string_rev(unsigned char* str){
    int i = 0;
    while (*(str+i)!='\0'){
        i++;
    }
    char temp;
    int x = 0;

    while (i > x){
        temp = *(str + i -1);
        *((str+i)-1) = *(str+x);
        *(str+x) = temp;
        i--;x++;
    }
    // *str = temp;
}
char *string_chr(const char* str, const char c){

    int i = 0;
    while (*(str+i)!=c && *(str+i)!='\0'){
        i++;
    }
    if (*(str+i)==c){
        return (char*) (str+i);
    } else if (*(str+i)=='\0'){
        return NULL;
    }
    return NULL; //hoffentlich komme ich nie hier hin
}