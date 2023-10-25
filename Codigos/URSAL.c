#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDIDATES 10000

typedef struct {
    int num;
    int votos;
    int tipo;
} Candidato;

Candidato candidates[MAX_CANDIDATES];

int compare(const void *a, const void *b) {
    Candidato *c1 = (Candidato*)a;
    Candidato *c2 = (Candidato*)b;

    if (c1->votos == c2->votos) {
        return c1->num - c2->num;
    }

    return c2->votos - c1->votos;
}

int main() {
    int sen, fed, est, validos = 0, invalidos = 0, total_candidates = 0;
    int recep;
    scanf("%d %d %d", &sen, &fed, &est);

    while (scanf("%d", &recep) == 1) {
        if (recep < 0) {
            invalidos++;
            continue;
        } else {
            validos++;
        }

        int i;
        for (i = 0; i < total_candidates; i++) {
            if (candidates[i].num == recep) {
                candidates[i].votos++;
                break;
            }
        }

        if (i == total_candidates) {
            if (recep < 100) {
                candidates[total_candidates].tipo = 1;
            } else if (recep < 1000) {
                candidates[total_candidates].tipo = 2;
            } else if (recep < 10000) {
                candidates[total_candidates].tipo = 3;
            } else {
                candidates[total_candidates].tipo = 4;
            }
            candidates[total_candidates].num = recep;
            candidates[total_candidates].votos = 1;
            total_candidates++;
        }
    }
    qsort(candidates, total_candidates, sizeof(Candidato), compare);

    // print results
    printf("Presidente:\n");
    int i;
    for (i = 0; i < total_candidates; i++) {
        if (candidates[i].tipo == 1) {
            printf("%d %d\n", candidates[i].num, candidates[i].votos);
        }
    }

    printf("Senadores:\n");
    for (i = 0; i < total_candidates; i++) {
        if (candidates[i].tipo == 2) {
            printf("%d %d\n", candidates[i].num, candidates[i].votos);6


            
        }
    }

    printf("Deputados Federais:\n");
    for (i = 0; i < total_candidates; i++) {
    if (candidates[i].tipo == 3) {
    printf("%d %d\n", candidates[i].num, candidates[i].votos);
    }
    }
    printf("Deputados Estaduais:\n");
for (i = 0; i < total_candidates; i++) {
    if (candidates[i].tipo == 4) {
        printf("%d %d\n", candidates[i].num, candidates[i].votos);
    }
}

printf("Votos válidos: %d\n", validos);
printf("Votos inválidos: %d\n", invalidos);

return 0;
}