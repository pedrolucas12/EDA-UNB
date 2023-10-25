#include <stdio.h>
#include <string.h>

#define MAX_LEN 100000

char input[MAX_LEN+1];
int stack[MAX_LEN];
int top = -1;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", input);
        top = -1;
        int len = strlen(input);
        int valid = 1;
        for (int i = 0; i < len; i++) {
            if (input[i] == '(' || input[i] == '[' || input[i] == '{') {
                stack[++top] = input[i];
            } else {
                if (top == -1) {
                    valid = 0;
                    break;
                }
                if (input[i] == ')' && stack[top] != '(') {
                    valid = 0;
                    break;
                }
                if (input[i] == ']' && stack[top] != '[') {
                    valid = 0;
                    break;
                }
                if (input[i] == '}' && stack[top] != '{') {
                    valid = 0;
                    break;
                }
                top--;
            }
        }
        if (valid && top == -1) {
            printf("S\n");
        } else {
            printf("N\n");
        }
    }
    return 0;
}