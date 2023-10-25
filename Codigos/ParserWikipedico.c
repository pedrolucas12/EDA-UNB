//Pedro Lucas Santana
//202017049

//Parser Wikipédico

#include <stdio.h>
#include <string.h>

#define MAX_LEN 999900000

int main() {
    int n;
    scanf("%d\n", &n);

    char text[MAX_LEN];
    int stack[MAX_LEN];
    int top = -1;

    while (n--) {
        fgets(text, MAX_LEN, stdin);
        int len = strlen(text);

        for (int i = 0; i < len; i++) {
            if (text[i] == '*') {
                stack[++top] = 1;
            } else if (text[i] == '/') {
                stack[++top] = 2;
            } else if (text[i] == '_') {
                stack[++top] = 3;
            } else if (text[i] == '*' && top >= 0 && stack[top] == 1) {
                top--;
            } else if (text[i] == '/' && top >= 0 && stack[top] == 2) {
                top--;
            } else if (text[i] == '_' && top >= 0 && stack[top] == 3) {
                top--;
            }
        }

        if (top != -1) {
            printf("E\n");
            return 0;
        }
    }

    printf("C\n");
    return 0;
}