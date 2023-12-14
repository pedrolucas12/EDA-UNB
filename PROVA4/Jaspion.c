#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct que guarda a palavra em japones e sua traducao
typedef struct tradutor {
    char japones[100];
    char portugues[100];
} tradutor;

//Funções de merge e merge_sort para ordenação das palavras em japonês
void merge(tradutor *v, int l, int m, int r) {
    tradutor *auxiliar = malloc(sizeof(tradutor) * (r - l));

    int i = l, j = m, k = 0;
    while (i < m && j < r)
        auxiliar[k++] = strcmp(v[i].japones, v[j].japones) <= 0 ? v[i++] : v[j++];

    while (i < m)
        auxiliar[k++] = v[i++];
    while (j < r)
        auxiliar[k++] = v[j++];

    for (i = l; i < r; i++)
        v[i] = auxiliar[i - l];

    free(auxiliar);
}

void merge_sort(tradutor *v, int l, int r) {
    if (r - 1 <= l)
        return;

    int meio = l + (r - l) / 2;

    merge_sort(v, l, meio);
    merge_sort(v, meio, r);
    merge(v, l, meio, r);
}

//Função busca binária que retorna o índice do dado no vetor caso exista, caso não retorna -1
int busca_binaria(tradutor *v, int n, char *dado) {
    int l = 0, h = n;

    while (h >= l) {
        int meio = l + (h - l) / 2;
        if (!strcmp(v[meio].japones, dado))
            return meio;
        else if (strcmp(v[meio].japones, dado) > 0)
            h = meio - 1;
        else
            l = meio + 1;
    }
    return -1;
}

//Não pode ler as entradas com scanf, pois ele não le a partir de um espaço ' '
int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        int m, n;

        scanf("%d %d", &m, &n);

        tradutor *vetor = malloc(sizeof(tradutor) * m);
        char frase[100];

        for (int i = 0; i < m; i++) {
            //Lendo as entradas, as armazenando e suas traduções nas structs
            scanf("\n");    //Consumindo a linha vazia com scanf

            //Lendo entradas
            fgets(vetor[i].japones, sizeof(vetor[i].japones), stdin);
            fgets(vetor[i].portugues, sizeof(vetor[i].portugues), stdin);

            //Usando a função strcspn para encontrar o índice que contém '\n' e substitui-lo por '\0'
            vetor[i].japones[strcspn(vetor[i].japones, "\n")] = '\0';
            vetor[i].portugues[strcspn(vetor[i].portugues, "\n")] = '\0';
        }

        //Ordenando as palavras em ordem alfabética (em japonês)
        merge_sort(vetor, 0, m);

        //Fazendo a leitura das palavras e buscando no vetor
        while (n--) {
            int indice = 0;
            int i_palavra = 0;

            scanf("\n");
            fgets(frase, sizeof(frase), stdin);
            frase[strcspn(frase, "\n")] = '\0';

            while (1) {
                char palavra[100];
                while (frase[indice] != ' ' && frase[indice] != '\0')
                    palavra[i_palavra++] = frase[indice++];

                palavra[i_palavra] = '\0';
                indice++;

                int resposta = busca_binaria(vetor, m, palavra);

                if (resposta == -1)
                    printf("%s", palavra);
                else
                    printf("%s", vetor[resposta].portugues);

                if (frase[indice] == '\0')
                    break;
                else
                    printf(" ");
                
                i_palavra = 0;
            }
            printf("\n");
        }
    }

    return 0;
}