#include <stdio.h>
#include <stdlib.h>

//Struct que salva os digitos do candidato e os votos
typedef struct candidato {
    int votos, digitos;
} candidato;

//Funções merge e merge_sort que ordenam com base na quantidade de votos
void merge(candidato *v, int l, int m, int r) {
    candidato *auxiliar = malloc(sizeof(candidato) * (r - l));

    int i = l, j = m, k = 0;

    while (i < m && j < r)
        auxiliar[k++] = v[i].votos <= v[j].votos ? v[i++] : v[j++];

    while (i < m)
        auxiliar[k++] = v[i++];
    while (j < r)
        auxiliar[k++] = v[j++];

    for (i = l; i < r; i++)
        v[i] = auxiliar[i - l];

    free(auxiliar);
}
void merge_sort(candidato *v, int l, int r) {
    if (r - 1 <= l)
        return;

    int meio = l + (r - l) / 2;

    merge_sort(v, l, meio);
    merge_sort(v, meio, r);
    merge(v, l, meio, r);
}

int main() {
    //Inicializando variáveis e vetor de structs candidatos
    candidato *vetor = malloc(sizeof(candidato) * 100001);
    int s, f, e, voto, votos_validos = 0, votos_invalidos = 0;
    int votos_totais = 0;

    //Lendo variáveis
    scanf("%d %d %d", &s, &f, &e);

    //Inicializando o vetor com as 100000 possibilidades de digitos
    for (int i = 10; i < 100000; i++)
        vetor[i].digitos = i;

    //Lendo as entradas dos digitos contabilizando a quantidade de votos
    while (scanf("%d", &voto) != EOF)
        //Não existe a possibilidade de um voto valido ser menor que 10
        if (voto >= 10) {
            //Incrementando o valor dos votos validos e o valor do atributo votos da struct candidato referente
            votos_validos++;
            vetor[voto].votos++;
        }
        else
            votos_invalidos++;

    //Ordenando o vetor quanto aos votos para cada cargo (presidente 10-100, senador 100-1000, etc.)
    for (int i = 0, m = 10; i < 4; i++, m *= 10)
        merge_sort(vetor, m, m * 10);

    //Fazendo a contagem de votos para presidente
    for (int i = 99; i >= 10; i--)
        votos_totais += vetor[i].votos;

    //Imprimindo os resultados
    printf("%d %d\n", votos_validos, votos_invalidos);

    int percentual = (float)vetor[99].votos / (float)votos_totais >= 0.51 ? 1 : 0;

    if (percentual)
        printf("%d\n", vetor[99].digitos);
    else
        printf("Segundo turno\n");

    for (int i = 999; s; i--, s--)
        printf("%d ", vetor[i].digitos);
    printf("\n");

    for (int i = 9999; f; i--, f--)
        printf("%d ", vetor[i].digitos);
    printf("\n");

    for (int i = 99999; e; i--, e--)
        printf("%d ", vetor[i].digitos);
    printf("\n");

    printf("\n");
    
    return 0;
}