//Operacoes de Busca Binaria Simples

//Busca Binaria Iterativa
int buscaBinariaIterativa(int *vetor, int tamanho, int valor){
    int inicio = 0; 
    int fim = tamanho-1;
    int meio;
    while(inicio <= fim){ 
        meio = (inicio+fim)/2; //Calcula o meio do vetor
        if(valor == vetor[meio]){ //Verifica se o valor esta no meio
            return meio;
        }else if(valor < vetor[meio]){ //Verifica se o valor esta na primeira metade do vetor
            fim = meio-1;
        }else{ //Verifica se o valor esta na segunda metade do vetor
            inicio = meio+1;
        }
    }
    return -1;
}

//Busca Binaria Recursiva
int buscaBinariaRecursiva(int *vetor, int inicio, int fim, int valor){
    if(inicio > fim){
        return -1;
    }
    int meio = (inicio+fim)/2; //Calcula o meio do vetor
    if(valor == vetor[meio]){ //Verifica se o valor esta no meio
        return meio;
    }else if(valor < vetor[meio]){ //Verifica se o valor esta na primeira metade do vetor
        return buscaBinariaRecursiva(vetor, inicio, meio-1, valor);
    }else{ //Verifica se o valor esta na segunda metade do vetor
        return buscaBinariaRecursiva(vetor, meio+1, fim, valor);
    }
}
