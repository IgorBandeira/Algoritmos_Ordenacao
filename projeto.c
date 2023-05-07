#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include "projeto.h"

#define RUN 2

// Algoritmo QuickSort
void quickSort(int vetor[], int esquerda, int direita) {
    int i, j, pivo, aux;
    i = esquerda;
    j = direita;
    pivo = vetor[(esquerda + direita) / 2];

    while (i <= j) {
        while (vetor[i] < pivo && i < direita) {
            i++;
        }
        while (vetor[j] > pivo && j > esquerda) {
            j--;
        }
        if (i <= j) {
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i++;
            j--;
        }
    }
    if (j > esquerda) {
        quickSort(vetor, esquerda, j);
    }
    if (i < direita) {
        quickSort(vetor, i, direita);
    }
}

// Algoritmo MergeSort
void merge(int arr[], int inicio, int meio, int fim) {
    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int INICIO[n1], FIM[n2];

    for (i = 0; i < n1; i++)
        INICIO[i] = arr[inicio + i];
    for (j = 0; j < n2; j++)
        FIM[j] = arr[meio + 1 + j];

    i = 0;
    j = 0;
    k = inicio;

    while (i < n1 && j < n2) {
        if (INICIO[i] <= FIM[j]) {
            arr[k] = INICIO[i];
            i++;
        } else {
            arr[k] = FIM[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = INICIO[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = FIM[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        mergeSort(arr, inicio, meio);
        mergeSort(arr, meio + 1, fim);

        merge(arr, inicio, meio, fim);
    }
}

// Algoritmo InsertionSort
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Algoritmo SelectionSort
void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Algoritmo HeapSort
void heapify(int vet[], int n, int i) {
    int max = i;

    int e = 2 * i + 1;
    int d = 2 * i + 2;

    if (e < n && vet[e] > vet[max])
        max = e;

    if (d < n && vet[d] > vet[max])
        max = d;

    if (max != i) {
        int aux = vet[i];
        vet[i] = vet[max];
        vet[max] = aux;

        heapify(vet, n, max);
    }
}

void heapSort(int vet[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(vet, n, i);

    for (int i = n - 1; i >= 0; i--) {
        int aux = vet[0];
        vet[0] = vet[i];
        vet[i] = aux;

        heapify(vet, i, 0);
    }
}

// Algoritmo BubbleSort
void bubbleSort(int *v, int n) {
    int i, continua, aux, fim = n;
    do {
        continua = 0;
        for (i = 0; i < fim - 1; i++) {
            if (v[i] > v[i + 1]) {
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                continua = i;
            }
        }
        fim--;
    } while (continua != 0);
}

// Algoritmo ShellSort
void shellSort(int L[], int n) {
    int temp, i, j, m;
    for (m = n / 2; m > 0; m /= 2) {
        for (j = m; j < n; j++) {
            for (i = j - m; i >= 0; i -= m) {
                if (L[i + m] >= L[i])
                    break;
                else {
                    temp = L[i];
                    L[i] = L[i + m];
                    L[i + m] = temp;
                }
            }
        }
    }
}

// Algoritmo TimSort
void insertion(int arr[], int l, int r) {
    if (arr == NULL || l>=r) return;

    int key;
    int i, j;
    for (i=l+1; i<=r; i++) {
        key = arr[i];
        j = i-1;
        while (j>=l && arr[j]>key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

}

void mergesort(int arr[], int temp[], int l, int m, int r) {
    if (arr == NULL || temp == NULL) return;
    if (l > m || m+1 > r) return;

    int i = l;
    int j = m + 1;
    int start = l;

    while (i <= m && j <= r) {
        if (arr[i] < arr[j]) {
            temp[start++] = arr[i++];
        } else if (arr[i] == arr[j]) {

            temp[start++] = arr[i++];
            temp[start++] = arr[j++];
        } else {
            temp[start++] = arr[j++];
        }

    }

    while (i <= m) {
        temp[start++] = arr[i++];
    }


    while (j <= r) {
        temp[start++] = arr[j++];
    }

    for (i = l; i <= r; i++) {
        arr[i] = temp[i];
    }
}

int minsort(int arg1, int arg2) {
    if (arg1 <= arg2) {
        return arg1;
    } else {
        return arg2;
    }
}

void timSort(int arr[], unsigned int size) {
    if (arr == NULL || size <= 1) return;
    for (int i=0; i < size; i+=RUN) {
        insertion(arr, i, minsort(i+RUN-1, size-1));
    }

    int* temp = (int*)malloc(sizeof(int)*size);


    int l, m, r, n;
    for (n=RUN; n < size; n*=2) {
        for (l=0; l < size; l+=2*n) {
            m = l+n-1;
            r = minsort(l+2*n-1, size-1);
            if (m<r) {
                mergesort(arr, temp, l, m, r);
            }
        }
    }
    free(temp);
}

// Algoritmo RadixSort
int find_max(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void radix_sort(int arr[], int n) {
    int max = find_max(arr, n);
    int exp = 1;
    int *temp = malloc(n * sizeof(int));
    while (max / exp > 0) {
        int count[10] = {0};
        for (int i = 0; i < n; i++) {
            count[(arr[i] / exp) % 10]++;
        }
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            temp[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }
        for (int i = 0; i < n; i++) {
            arr[i] = temp[i];
        }
        exp *= 10;
    }
    free(temp);
}

