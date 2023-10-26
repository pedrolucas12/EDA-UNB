#include <stdio.h>

void inverte(char *string){
    if(string[0] != '\0'){
        inverte(&string[1]);
        printf("%c", string[0]);
    }
}

int main(){
    char palavra[501];

    scanf("%s", palavra);
    inverte(palavra);
    printf("\n");

    return 0;
}