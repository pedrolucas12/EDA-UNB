//Implementacao do Algoritmo de Ordenacao QuickSort

//QuickSort
void QuickSort(int *vetor, int inicio, int fim){
    int pivo, aux, i, j, meio;
    i = inicio;
    j = fim;
    meio = (int) ((i + j) / 2); //Calcula o meio do vetor
    pivo = vetor[meio]; //Pivo é o elemento do meio do vetor
    do{ //Divide o vetor em duas partes
        while (vetor[i] < pivo) i = i + 1; //Enquanto o valor da esquerda for menor que o pivo, continua a busca
        while (vetor[j] > pivo) j = j - 1; //Enquanto o valor da direita for maior que o pivo, continua a busca
        if(i <= j){ //Troca os valores da esquerda e da direita
            aux = vetor[i]; 
            vetor[i] = vetor[j]; 
            vetor[j] = aux;
            i = i + 1;
            j = j - 1;
        }
    }while(j > i); //Enquanto a esquerda for menor que a direita
    if(inicio < j) QuickSort(vetor, inicio, j); //Ordena a parte esquerda
    if(i < fim) QuickSort(vetor, i, fim); //Ordena a parte direita
}

//QuickSort com Mediana de 3
void QuickSortMediana(int *vetor, int inicio, int fim){
    int pivo, aux, i, j, meio;
    i = inicio;
    j = fim;
    meio = (int) ((i + j) / 2); //Calcula o meio do vetor
    pivo = Mediana(vetor[inicio], vetor[meio], vetor[fim]); //Pivo é a mediana de 3
    do{ //Divide o vetor em duas partes
        while (vetor[i] < pivo) i = i + 1; //Enquanto o valor da esquerda for menor que o pivo, continua a busca
        while (vetor[j] > pivo) j = j - 1; //Enquanto o valor da direita for maior que o pivo, continua a busca
        if(i <= j){ //Troca os valores da esquerda e da direita
            aux = vetor[i]; 
            vetor[i] = vetor[j]; 
            vetor[j] = aux;
            i = i + 1;
            j = j - 1;
        }
    }while(j > i); //Enquanto a esquerda for menor que a direita
    if(inicio < j) QuickSortMediana(vetor, inicio, j); //Ordena a parte esquerda
    if(i < fim) QuickSortMediana(vetor, i, fim); //Ordena a parte direita
}

//QuickSort com Insercao
void QuickSortInsercao(int *vetor, int inicio, int fim){
    int pivo, aux, i, j, meio;
    i = inicio;
    j = fim;
    meio = (int) ((i + j) / 2); //Calcula o meio do vetor
    pivo = vetor[meio]; //Pivo é o elemento do meio do vetor
    do{ //Divide o vetor em duas partes
        while (vetor[i] < pivo) i = i + 1; //Enquanto o valor da esquerda for menor que o pivo, continua a busca
        while (vetor[j] > pivo) j = j - 1; //Enquanto o valor da direita for maior que o pivo, continua a busca
        if(i <= j){ //Troca os valores da esquerda e da direita
            aux = vetor[i]; 
            vetor[i] = vetor[j]; 
            vetor[j] = aux;
            i = i + 1;
            j = j - 1;
        }
    }while(j > i); //Enquanto a esquerda for menor que a direita
    if(inicio < j) QuickSortInsercao(vetor, inicio, j); //Ordena a parte esquerda
    if(i < fim) QuickSortInsercao(vetor, i, fim); //Ordena a parte direita
}

//QuickSort com Mediana de 3 e Insercao
void QuickSortMedianaInsercao(int *vetor, int inicio, int fim){
    int pivo, aux, i, j, meio;
    i = inicio;
    j = fim;
    meio = (int) ((i + j) / 2); //Calcula o meio do vetor
    pivo = Mediana(vetor[inicio], vetor[meio], vetor[fim]); //Pivo é a mediana de 3
    do{ //Divide o vetor em duas partes
        while (vetor[i] < pivo) i = i + 1; //Enquanto o valor da esquerda for menor que o pivo, continua a busca
        while (vetor[j] > pivo) j = j - 1; //Enquanto o valor da direita for maior que o pivo, continua a busca
        if(i <= j){ //Troca os valores da esquerda e da direita
            aux = vetor[i]; 
            vetor[i] = vetor[j]; 
            vetor[j] = aux;
            i = i + 1;
            j = j - 1;
        }
    }while(j > i); //Enquanto a esquerda for menor que a direita
    if(inicio < j) QuickSortMedianaInsercao(vetor, inicio, j); //Ordena a parte esquerda
    if(i < fim) QuickSortMedianaInsercao(vetor, i, fim); //Ordena a parte direita
}

//QuickSort com Mediana de 3 OTIMIZADA 
void QuickSortMedianaOtimizada(int *vetor, int inicio, int fim){
    int pivo, aux, i, j, meio;
    i = inicio;
    j = fim;
    meio = (int) ((i + j) / 2); //Calcula o meio do vetor
    pivo = MedianaOtimizada(vetor[inicio], vetor[meio], vetor[fim]); //Pivo é a mediana de 3
    do{ //Divide o vetor em duas partes
        while (vetor[i] < pivo) i = i + 1; //Enquanto o valor da esquerda for menor que o pivo, continua a busca
        while (vetor[j] > pivo) j = j - 1; //Enquanto o valor da direita for maior que o pivo, continua a busca
        if(i <= j){ //Troca os valores da esquerda e da direita
            aux = vetor[i]; 
            vetor[i] = vetor[j]; 
            vetor[j] = aux;
            i = i + 1;
            j = j - 1;
        }
    }while(j > i); //Enquanto a esquerda for menor que a direita
    if(inicio < j) QuickSortMedianaOtimizada(vetor, inicio, j); //Ordena a parte esquerda
    if(i < fim) QuickSortMedianaOtimizada(vetor, i, fim); //Ordena a parte direita
}

//QuickSort three-way iterativo( divide o vetor em 3 partes)
void QuickSortThreeWay(int *vetor, int inicio, int fim){
    int pivo, aux, i, j, meio;
    i = inicio;
    j = fim;
    meio = (int) ((i + j) / 2); //Calcula o meio do vetor
    pivo = vetor[meio]; //Pivo é o elemento do meio do vetor
    do{ //Divide o vetor em duas partes
        while (vetor[i] < pivo) i = i + 1; //Enquanto o valor da esquerda for menor que o pivo, continua a busca
        while (vetor[j] > pivo) j = j - 1; //Enquanto o valor da direita for maior que o pivo, continua a busca
        if(i <= j){ //Troca os valores da esquerda e da direita
            aux = vetor[i]; 
            vetor[i] = vetor[j]; 
            vetor[j] = aux;
            i = i + 1;
            j = j - 1;
        }
    }while(j > i); //Enquanto a esquerda for menor que a direita
    if(inicio < j) QuickSortThreeWay(vetor, inicio, j); //Ordena a parte esquerda
    if(i < fim) QuickSortThreeWay(vetor, i, fim); //Ordena a parte direita
}

//QuickSort three-way iterativo( divide o vetor em 3 partes) com Mediana de 3
void QuickSortThreeWayMediana(int *vetor, int inicio, int fim){
    int pivo, aux, i, j, meio;
    i = inicio;
    j = fim;
    meio = (int) ((i + j) / 2); //Calcula o meio do vetor
    pivo = Mediana(vetor[inicio], vetor[meio], vetor[fim]); //Pivo é a mediana de 3
    do{ //Divide o vetor em duas partes
        while (vetor[i] < pivo) i = i + 1; //Enquanto o valor da esquerda for menor que o pivo, continua a busca
        while (vetor[j] > pivo) j = j - 1; //Enquanto o valor da direita for maior que o pivo, continua a busca
        if(i <= j){ //Troca os valores da esquerda e da direita
            aux = vetor[i]; 
            vetor[i] = vetor[j]; 
            vetor[j] = aux;
            i = i + 1;
            j = j - 1;
        }
    }while(j > i); //Enquanto a esquerda for menor que a direita
    if(inicio < j) QuickSortThreeWayMediana(vetor, inicio, j); //Ordena a parte esquerda
    if(i < fim) QuickSortThreeWayMediana(vetor, i, fim); //Ordena a parte direita
}

//QuickSort three-way iterativo( divide o vetor em 3 partes) com Insercao
void QuickSortThreeWayInsercao(int *vetor, int inicio, int fim){
    int pivo, aux, i, j, meio;
    i = inicio;
    j = fim;
    meio = (int) ((i + j) / 2); //Calcula o meio do vetor
    pivo = vetor[meio]; //Pivo é o elemento do meio do vetor
    do{ //Divide o vetor em duas partes
        while (vetor[i] < pivo) i = i + 1; //Enquanto o valor da esquerda for menor que o pivo, continua a busca
        while (vetor[j] > pivo) j = j - 1; //Enquanto o valor da direita for maior que o pivo, continua a busca
        if(i <= j){ //Troca os valores da esquerda e da direita
            aux = vetor[i]; 
            vetor[i] = vetor[j]; 
            vetor[j] = aux;
            i = i + 1;
            j = j - 1;
        }
    }while(j > i); //Enquanto a esquerda for menor que a direita
    if(inicio < j) QuickSortThreeWayInsercao(vetor, inicio, j); //Ordena a parte esquerda
    if(i < fim) QuickSortThreeWayInsercao(vetor, i, fim); //Ordena a parte direita
}

//QuickSort three-way iterativo( divide o vetor em 3 partes) com Mediana de 3 e Insercao
void QuickSortThreeWayMedianaInsercao(int *vetor, int inicio, int fim){
    int pivo, aux, i, j, meio;
    i = inicio;
    j = fim;
    meio = (int) ((i + j) / 2); //Calcula o meio do vetor
    pivo = Mediana(vetor[inicio], vetor[meio], vetor[fim]); //Pivo é a mediana de 3
    do{ //Divide o vetor em duas partes
        while (vetor[i] < pivo) i = i + 1; //Enquanto o valor da esquerda for menor que o pivo, continua a busca
        while (vetor[j] > pivo) j = j - 1; //Enquanto o valor da direita for maior que o pivo, continua a busca
        if(i <= j){ //Troca os valores da esquerda e da direita
            aux = vetor[i]; 
            vetor[i] = vetor[j]; 
            vetor[j] = aux;
            i = i + 1;
            j = j - 1;
        }
    }while(j > i); //Enquanto a esquerda for menor que a direita
    if(inicio < j) QuickSortThreeWayMedianaInsercao(vetor, inicio, j); //Ordena a parte esquerda
    if(i < fim) QuickSortThreeWayMedianaInsercao(vetor, i, fim); //Ordena a parte direita
}


//Altura da pilha com QuickSort
int AlturaPilhaQuickSort(int *vetor, int inicio, int fim){
    int pivo, aux, i, j, meio, altura = 0;
    i = inicio;
    j = fim;
    meio = (int) ((i + j) / 2); //Calcula o meio do vetor
    pivo = vetor[meio]; //Pivo é o elemento do meio do vetor
    do{ //Divide o vetor em duas partes
        while (vetor[i] < pivo) i = i + 1; //Enquanto o valor da esquerda for menor que o pivo, continua a busca
        altura++;
        while (vetor[j] > pivo) j = j - 1; //Enquanto o valor da direita for maior que o pivo, continua a busca
        altura++;
        if(i <= j){ //Troca os valores da esquerda e da direita
            aux = vetor[i]; 
            vetor[i] = vetor[j]; 
            vetor[j] = aux;
            altura++;
            i = i + 1;
            j = j - 1;
        }
    }while(j > i); //Enquanto a esquerda for menor que a direita
    
    if(inicio < j) altura += AlturaPilhaQuickSort(vetor, inicio, j); //Ordena a parte esquerda
    if(i < fim) altura += AlturaPilhaQuickSort(vetor, i, fim); //Ordena a parte direita
    return altura;
}