#include <stdio.h>
#include <ctype.h>

int main() {
    int N, M, A, K;
    scanf("%d %d %d %d", &N, &M, &A, &K);
    
    char senha[1001];
    scanf("%s", senha);
    
    int cont_min = 0, cont_maius = 0, cont_num = 0;
    
    for (int i = 0; senha[i] != '\0'; i++) {
        if (islower(senha[i])) {
            cont_min++;
        } else if (isupper(senha[i])) {
            cont_maius++;
        } else if (isdigit(senha[i])) {
            cont_num++;
        }
    }
    
    if (strlen(senha) >= N && cont_min >= M && cont_maius >= A && cont_num >= K) {
        printf("Ok =/\n");
    } else {
        printf("Ufa :)\n");
    }
    
    return 0;
}
