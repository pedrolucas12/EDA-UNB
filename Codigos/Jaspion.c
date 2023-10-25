#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char jap[81];
    char br[81];
} Translater;

typedef struct
{
    char jap[81];
    char br[81];
} Letra;

void translate(Translater *trad, Letra *letra, int lenL, int lenT)
{
    int i, j;
    for (i = 0; i < lenL; i++)
    {
        char translation[81] = {0};
        char *linha = strdup(letra[i].jap);
        char *token = strtok(linha, " ");
        while (token != NULL)
        {
            for (j = 0; j < lenT; j++)
            { if (strcmp(token, trad[j].jap) == 0)
{
snprintf(translation + strlen(translation), sizeof(translation) - strlen(translation), "%s ", trad[j].br);
break;
}
}
token = strtok(NULL, " ");
}
snprintf(letra[i].br, sizeof(letra[i].br), "%s", translation);
free(linha);
}
}

int main()
{
Translater *trad;
Letra *letra;
int inst, dic, musc, k;
scanf("%d", &inst);

while (inst--)
{
    scanf("%d %d", &dic, &musc);
    trad = (Translater*)malloc(sizeof(Translater) * dic);
    letra = (Letra*)malloc(sizeof(Letra) * musc);

    for (int i = 0; i < dic; i++)
    {
        scanf("%80s", trad[i].jap);
        scanf("%80s", trad[i].br);
    }

    for (int j = 0; j < musc; j++)
    {
        scanf("%80s", letra[j].jap);
    }
    translate(trad, letra, musc, dic);

    for (k = 0; k < musc; k++)
    {
        printf("%s\n", letra[k].br);
    }
    free(trad);
    free(letra);
}
return 0;
}