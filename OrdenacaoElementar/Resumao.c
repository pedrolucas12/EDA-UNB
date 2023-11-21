// Função de partição para o Quick Sort
int partition(int lista[], int inicio, int fim) {
    int pivot = lista[fim];
    int i = inicio;
    
    for (int j = inicio; j < fim; j++) {
        if (lista[j] <= pivot) {
            // Troca de elementos nas posições j e i
            int temp = lista[j];
            lista[j] = lista[i];
            lista[i] = temp;
            // Incrementa-se o limite dos elementos menores que o pivô
            i = i + 1;
        }
    }
    
    // Troca do pivô com o elemento na posição i
    int temp = lista[i];
    lista[i] = lista[fim];
    lista[fim] = temp;

    return i;
}

// Função recursiva para o Quick Sort
void quicksort(int lista[], int inicio, int fim) {
    if (inicio < fim) {
        int p = partition(lista, inicio, fim);
        // Recursivamente na sublista à esquerda (menores)
        quicksort(lista, inicio, p-1);
        // Recursivamente na sublista à direita (maiores)
        quicksort(lista, p+1, fim);
    }
}

// Função de intercalação para o Merge Sort
void merge(int lista[], int inicio, int meio, int fim) {
    int left_size = meio - inicio;
    int right_size = fim - meio;

    int left[left_size];
    int right[right_size];

    // Preenche as listas temporárias left e right
    for (int i = 0; i < left_size; i++) {
        left[i] = lista[inicio + i];
    }

    for (int j = 0; j < right_size; j++) {
        right[j] = lista[meio + j];
    }

    int top_left = 0, top_right = 0;
    int k = inicio;

    // Intercala os elementos das listas left e right na lista principal
    while (top_left < left_size && top_right < right_size) {
        if (left[top_left] <= right[top_right]) {
            lista[k] = left[top_left];
            top_left++;
        } else {
            lista[k] = right[top_right];
            top_right++;
        }
        k++;
    }

    // Adiciona os elementos restantes de left, se houver
    while (top_left < left_size) {
        lista[k] = left[top_left];
        top_left++;
        k++;
    }

    // Adiciona os elementos restantes de right, se houver
    while (top_right < right_size) {
        lista[k] = right[top_right];
        top_right++;
        k++;
    }
}

// Função recursiva para o Merge Sort
void mergesort(int lista[], int inicio, int fim) {
    if (fim - inicio > 1) {
        int meio = (fim + inicio) / 2;
        mergesort(lista, inicio, meio);
        mergesort(lista, meio, fim);
        merge(lista, inicio, meio, fim);
    }
}

// Função para o Insertion Sort
void insertion_sort(int lista[], int n) {
    for (int i = 1; i < n; i++) {
        int chave = lista[i];
        int j = i - 1;
        while (j >= 0 && lista[j] > chave) {
            lista[j+1] = lista[j];
            j = j - 1;
        }
        lista[j+1] = chave;
    }
    // Complexidade de tempo O(n^2)
    // Complexidade de espaço O(n)
}

// Função para o Bubble Sort
void bubble_sort(int lista[], int n) {
    for (int j = 0; j < n-1; j++) {
        for (int i = 0; i < n-1; i++) {
            if (lista[i] > lista[i+1]) {
                // Troca de elementos nas posições i e i+1
                int temp = lista[i];
                lista[i] = lista[i+1];
                lista[i+1] = temp;
            }
        }
    }
    // Complexidade de tempo O(n^2)
    // Complexidade de espaço O(n)
}

// Função para o Selection Sort
void selection_sort(int lista[], int n) {
    for (int j = 0; j < n-1; j++) {
        int min_index = j;
        for (int i = j; i < n; i++) {
            if (lista[i] < lista[min_index]) {
                min_index = i;
            }
        }
        if (lista[j] > lista[min_index]) {
            // Troca de elementos nas posições j e min_index
            int aux = lista[j];
            lista[j] = lista[min_index];
            lista[min_index] = aux;
        }
    }
    // 1 + (n-1)*[5 + X] = 1 + 5*(n-1) + X*(n-1)
    // Complexidade de tempo O(n^2)
    // Complexidade de espaço O(n)
}