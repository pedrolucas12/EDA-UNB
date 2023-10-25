#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 100

typedef struct {
    char nome[21];
    int problemas_resolvidos;
} Aluno;

int comparar_alunos(const void *a, const void *b) {
    const Aluno *aluno1 = (const Aluno *)a;
    const Aluno *aluno2 = (const Aluno *)b;
    
    // Primeiro, compara o número de problemas resolvidos (decrescente)
    if (aluno1->problemas_resolvidos > aluno2->problemas_resolvidos) {
        return -1;
    } else if (aluno1->problemas_resolvidos < aluno2->problemas_resolvidos) {
        return 1;
    } else {
        // Em caso de empate no número de problemas resolvidos, compara os nomes (crescente)
        return strcmp(aluno1->nome, aluno2->nome);
    }
}

int main() {
    int instancia = 1;
    while (1) {
        int n;
        scanf("%d", &n);
        if (n == 0) {
            break; // Fim da entrada
        }

        Aluno alunos[MAX_ALUNOS];
        
        for (int i = 0; i < n; i++) {
            scanf("%s %d", alunos[i].nome, &alunos[i].problemas_resolvidos);
        }

        // Ordena os alunos de acordo com as regras especificadas
        qsort(alunos, n, sizeof(Aluno), comparar_alunos);

        // O reprovado é o último colocado da competição
        printf("Instancia %d\n%s\n\n", instancia, alunos[n - 1].nome);
        instancia++;
    }

    return 0;
}
