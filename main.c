#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include "projeto.h"

int main() {
    int teste;
    do {
    struct timeval tempo_inicial, tempo_final;
    double deltaTempo;
    int tamanhoVetor;

        system("cls");
        printf("\tDigite um numero de 1 a 9 para escolher a funcao de ordenacao:\n\n");
        printf("\t\t1 - QuickSort\n");
        printf("\t\t2 - MergeSort\n");
        printf("\t\t3 - SelectionSort\n");
        printf("\t\t4 - InsertionSort\n");
        printf("\t\t5 - HeapSort\n");
        printf("\t\t6 - BubbleSort\n");
        printf("\t\t7 - ShellSort\n");
        printf("\t\t8 - TimSort\n");
        printf("\t\t9 - RadixSort\n\n");

        int opcaoAlgoritmo;
        scanf("%d", &opcaoAlgoritmo);

        switch (opcaoAlgoritmo) {
        case 1:
            system("cls"); // ou "clear" se estiver usando Linux ou MacOS
            printf("\tVoce escolheu o algoritmo QuickSort.\n\n");
            break;
        case 2:
            system("cls"); // ou "clear" se estiver usando Linux ou MacOS
            printf("\tVoce escolheu o algoritmo MergeSort.\n\n");
            break;
        case 3:
            system("cls"); // ou "clear" se estiver usando Linux ou MacOS
            printf("\tVoce escolheu o algoritmo SelectionSort.\n\n");
            break;
        case 4:
            system("cls"); // ou "clear" se estiver usando Linux ou MacOS
            printf("\tVoce escolheu o algoritmo InsertionSort.\n\n");
            break;
        case 5:
            system("cls"); // ou "clear" se estiver usando Linux ou MacOS
            printf("\tVoce escolheu o algoritmo HeapSort.\n\n");
            break;
        case 6:
            system("cls"); // ou "clear" se estiver usando Linux ou MacOS
            printf("\tVoce escolheu o algoritmo BubbleSort.\n");
            break;
        case 7:
            system("cls"); // ou "clear" se estiver usando Linux ou MacOS
            printf("\tVoce escolheu o algoritmo ShellSort.\n\n");
            break;
        case 8:
            system("cls"); // ou "clear" se estiver usando Linux ou MacOS
            printf("\tVoce escolheu o algoritmo TimSort.\n\n");
            break;
        case 9:
            system("cls"); // ou "clear" se estiver usando Linux ou MacOS
            printf("\tVoce escolheu o algoritmo RadixSort.\n\n");
            break;
        default:
            printf("\tOpcao invalida.\n");
            return 1;
        }

        printf("\tQuantos elementos voce deseja ordenar?\n\n");
        printf("\t\t1 - 1.000 elementos\n");
        printf("\t\t2 - 5.000 elementos\n");
        printf("\t\t3 - 10.000 elementos\n");
        printf("\t\t4 - 20.000 elementos\n");
        printf("\t\t5 - 50.000 elementos\n");
        printf("\t\t6 - 100.000 elementos\n\n");

        int opcaoTamanho;
        scanf("%d", &opcaoTamanho);

        switch (opcaoTamanho) {
        case 1:
            tamanhoVetor = 1000;
            break;
        case 2:
            tamanhoVetor = 5000;
            break;
        case 3:
            tamanhoVetor = 10000;
            break;
        case 4:
            tamanhoVetor = 20000;
            break;
        case 5:
            tamanhoVetor = 50000;
            break;
        case 6:
            tamanhoVetor = 100000;
            break;
        default:
            printf("Opcao invalida.\n");
            return 1;
        }

        int vetor[tamanhoVetor];

        double somaDeltaTempo = 0.0;
        double mediaDeltaTempo;

        // Ordena o vetor de acordo com a escolha do usuario
        switch (opcaoAlgoritmo) {
        case 1:
            // Algoritmo QuickSort
            for (int j = 0; j < 10; j++) {
                int *vetor = (int *)malloc(tamanhoVetor * sizeof(int));

                // Preenche o vetor com valores aleat�rios
                srand(time(NULL) + j); // Adiciona um valor diferente � seed do srand
                for (int i = 0; i < tamanhoVetor; i++) {
                    vetor[i] = rand() % 100;
                }

                // QuickSort no vetor e contando o tempo
                gettimeofday(&tempo_inicial, NULL);
                quickSort(vetor, 0, tamanhoVetor - 1);
                gettimeofday(&tempo_final, NULL);

                // Somando os 10 tempos
                double deltaTempo = (tempo_final.tv_sec + tempo_final.tv_usec / 1000000.0) - (tempo_inicial.tv_sec + tempo_inicial.tv_usec / 1000000.0); // Faz o calculo para deixar em segundos
                somaDeltaTempo += deltaTempo;

                free(vetor);
            }
            // Realizando a m�dia dos 10 tempos
            mediaDeltaTempo = somaDeltaTempo / 10.0;
            printf("Media de tempo de execucao do algoritmo foi de: %f segundos \n", mediaDeltaTempo);

            // Tempo do Comportamento Natural
            int *vetorNatural = (int *)malloc(tamanhoVetor * sizeof(int));
            for (int i = 0; i <= tamanhoVetor; i++) {
                vetorNatural[i] = i;
            }

            // Mede o tempo de execu��o do algoritmo para o comportamento natural
            gettimeofday(&tempo_inicial, NULL);
            quickSort(vetorNatural, 0, tamanhoVetor - 1);
            gettimeofday(&tempo_final, NULL);

            // Calcula o tempo decorrido
            double deltaTempoNatural = (tempo_final.tv_sec + tempo_final.tv_usec / 1000000.0) - (tempo_inicial.tv_sec + tempo_inicial.tv_usec / 1000000.0); // Faz o calculo para deixar em segundos
            printf("Tempo do comportamento natural do algoritmo foi de: %f segundos \n", deltaTempoNatural);

            // Tempo do Pior Caso:
            // Isso significa que os valores no vetor est�o em ordem decrescente, come�ando com "tamanhoVetor" na primeira posi��o e terminando com "1" na �ltima posi��o
            int *vetorPiorCaso = (int *)malloc(tamanhoVetor * sizeof(int));
            for (int i = 0; i <= tamanhoVetor; i++) {
                vetorPiorCaso[i] = tamanhoVetor - i;
            }

            // Mede o tempo de execu��o do algoritmo para o pior caso
            gettimeofday(&tempo_inicial, NULL);
            quickSort(vetorPiorCaso, 0, tamanhoVetor - 1);
            gettimeofday(&tempo_final, NULL);

            // Calcula o tempo decorrido
            double deltaTempoPior = (tempo_final.tv_sec + tempo_final.tv_usec / 1000000.0) - (tempo_inicial.tv_sec + tempo_inicial.tv_usec / 1000000.0); // Faz o calculo para deixar em segundos
            printf("Tempo do pior caso do algoritmo foi de: %f segundos \n", deltaTempoPior);

            // Libera a mem�ria alocada para os vetores
            free(vetorNatural);
            free(vetorPiorCaso);

            break;
        case 2:
            // Algoritmo MergeSort
            for (int j = 0; j < 10; j++) {
                int *vetor = (int *)malloc(tamanhoVetor * sizeof(int));

                // Preenche o vetor com valores aleat�rios
                srand(time(NULL) + j); // Adiciona um valor diferente � seed do srand
                for (int i = 0; i < tamanhoVetor; i++) {
                    vetor[i] = rand() % 100;
                }

                // MergeSort no vetor e contando o tempo
                gettimeofday(&tempo_inicial, NULL);
                mergeSort(vetor, 0, tamanhoVetor - 1);
                gettimeofday(&tempo_final, NULL);

                // Somando os 10 tempos
                double deltaTempo = (tempo_final.tv_sec + tempo_final.tv_usec / 1000000.0) - (tempo_inicial.tv_sec + tempo_inicial.tv_usec / 1000000.0); // Faz o calculo para deixar em segundos
                somaDeltaTempo += deltaTempo;

                free(vetor);
            }
            // Realizando a m�dia dos 10 tempos
            mediaDeltaTempo = somaDeltaTempo / 10.0;
            printf("Media de tempo de execucao do algoritmo foi de: %f segundos \n", mediaDeltaTempo);

            // Tempo do Comportamento Natural
            int *vetorNatural2 = (int *)malloc(tamanhoVetor * sizeof(int));
            for (int i = 0; i <= tamanhoVetor; i++) {
                vetorNatural2[i] = i;
            }

            // Mede o tempo de execu��o do algoritmo para o comportamento natural
            gettimeofday(&tempo_inicial, NULL);
            mergeSort(vetorNatural2, 0, tamanhoVetor - 1);
            gettimeofday(&tempo_final, NULL);

            // Calcula o tempo decorrido
            double deltaTempoNatural2 = (tempo_final.tv_sec + tempo_final.tv_usec / 1000000.0) - (tempo_inicial.tv_sec + tempo_inicial.tv_usec / 1000000.0); // Faz o calculo para deixar em segundos
            printf("Tempo do comportamento natural do algoritmo foi de: %f segundos \n", deltaTempoNatural2);

            // Tempo do Pior Caso:
            // Isso significa que os valores no vetor est�o em ordem decrescente, come�ando com "tamanhoVetor" na primeira posi��o e terminando com "1" na �ltima posi��o
            int *vetorPiorCaso2 = (int *)malloc(tamanhoVetor * sizeof(int));
            for (int i = 0; i <= tamanhoVetor; i++) {
                vetorPiorCaso2[i] = tamanhoVetor - i;
            }

            // Mede o tempo de execu��o do algoritmo para o pior caso
            gettimeofday(&tempo_inicial, NULL);
            mergeSort(vetorPiorCaso2, 0, tamanhoVetor - 1);
            gettimeofday(&tempo_final, NULL);

            // Calcula o tempo decorrido
            double deltaTempoPior2 = (tempo_final.tv_sec + tempo_final.tv_usec / 1000000.0) - (tempo_inicial.tv_sec + tempo_inicial.tv_usec / 1000000.0); // Faz o calculo para deixar em segundos
            printf("Tempo do pior caso do algoritmo foi de: %f segundos \n", deltaTempoPior2);

            // Libera a mem�ria alocada para os vetores
            free(vetorNatural2);
            free(vetorPiorCaso2);

            break;
        case 3:
            // Algoritmo SelectionSort
            for (int j = 0; j < 10; j++) {
                int *vetor = (int *)malloc(tamanhoVetor * sizeof(int));

                // Preenche o vetor com valores aleat�rios
                srand(time(NULL) + j); // Adiciona um valor diferente � seed do srand
                for (int i = 0; i < tamanhoVetor; i++) {
                    vetor[i] = rand() % 100;
                }

                // SelectionSort no vetor e contando o tempo
                gettimeofday(&tempo_inicial, NULL);
                selectionSort(vetor, tamanhoVetor);
                gettimeofday(&tempo_final, NULL);

                // Somando os 10 tempos
                double deltaTempo = (tempo_final.tv_sec + tempo_final.tv_usec / 1000000.0) - (tempo_inicial.tv_sec + tempo_inicial.tv_usec / 1000000.0); // Faz o calculo para deixar em segundos
                somaDeltaTempo += deltaTempo;

                free(vetor);
            }
            // Realizando a m�dia dos 10 tempos
            mediaDeltaTempo = somaDeltaTempo / 10.0;
            printf("Media de tempo de execucao do algoritmo foi de: %f segundos \n", mediaDeltaTempo);

            // Tempo do Comportamento Natural
            int *vetorNatural3 = (int *)malloc(tamanhoVetor * sizeof(int));
            for (int i = 0; i <= tamanhoVetor; i++) {
                vetorNatural3[i] = i;
            }

            // Mede o tempo de execu��o do algoritmo para o comportamento natural
            gettimeofday(&tempo_inicial, NULL);
            selectionSort(vetorNatural3, tamanhoVetor);
            gettimeofday(&tempo_final, NULL);

            // Calcula o tempo decorrido
            double deltaTempoNatural3 = (tempo_final.tv_sec + tempo_final.tv_usec / 1000000.0) - (tempo_inicial.tv_sec + tempo_inicial.tv_usec / 1000000.0); // Faz o calculo para deixar em segundos
            printf("Tempo do comportamento natural do algoritmo foi de: %f segundos \n", deltaTempoNatural3);

            // Tempo do Pior Caso:
            // Isso significa que os valores no vetor est�o em ordem decrescente, come�ando com "tamanhoVetor" na primeira posi��o e terminando com "1" na �ltima posi��o
            int *vetorPiorCaso3 = (int *)malloc(tamanhoVetor * sizeof(int));
            for (int i = 0; i <= tamanhoVetor; i++) {
                vetorPiorCaso3[i] = tamanhoVetor - i;
            }

            // Mede o tempo de execu��o do algoritmo para o pior caso
            gettimeofday(&tempo_inicial, NULL);
            selectionSort(vetorPiorCaso3, tamanhoVetor);
            gettimeofday(&tempo_final, NULL);

            // Calcula o tempo decorrido
            double deltaTempoPior3 = (tempo_final.tv_sec + tempo_final.tv_usec / 1000000.0) - (tempo_inicial.tv_sec + tempo_inicial.tv_usec / 1000000.0); // Faz o calculo para deixar em segundos
            printf("Tempo do pior caso do algoritmo foi de: %f segundos \n", deltaTempoPior3);

            // Libera a mem�ria alocada para os vetores
            free(vetorNatural3);
            free(vetorPiorCaso3);

            break;
        case 4:
            // Algoritmo InsertionSort
            for (int j = 0; j < 10; j++) {
                int *vetor = (int *)malloc(tamanhoVetor * sizeof(int));

                // Preenche o vetor com valores aleat�rios
                srand(time(NULL) + j); // Adiciona um valor diferente � seed do srand
                for (int i = 0; i < tamanhoVetor; i++) {
                    vetor[i] = rand() % 100;
                }

                // InsertionSort no vetor e contando o tempo
                gettimeofday(&tempo_inicial, NULL);
                insertionSort(vetor, tamanhoVetor);
                gettimeofday(&tempo_final, NULL);

                // Somando os 10 tempos
                double deltaTempo = (tempo_final.tv_sec + tempo_final.tv_usec / 1000000.0) - (tempo_inicial.tv_sec + tempo_inicial.tv_usec / 1000000.0); // Faz o calculo para deixar em segundos
                somaDeltaTempo += deltaTempo;

                free(vetor);
            }
            // Realizando a m�dia dos 10 tempos
            mediaDeltaTempo = somaDeltaTempo / 10.0;
            printf("Media de tempo de execucao do algoritmo foi de: %f segundos \n", mediaDeltaTempo);

            // Tempo do Comportamento Natural
            int *vetorNatural4 = (int *)malloc(tamanhoVetor * sizeof(int));
            for (int i = 0; i <= tamanhoVetor; i++) {
                vetorNatural4[i] = i;
            }

            // Mede o tempo de execu��o do algoritmo para o comportamento natural
            gettimeofday(&tempo_inicial, NULL);
            insertionSort(vetorNatural4, tamanhoVetor);
            gettimeofday(&tempo_final, NULL);

            // Calcula o tempo decorrido
            double deltaTempoNatural4 = (tempo_final.tv_sec + tempo_final.tv_usec / 1000000.0) - (tempo_inicial.tv_sec + tempo_inicial.tv_usec / 1000000.0); // Faz o calculo para deixar em segundos
            printf("Tempo do comportamento natural do algoritmo foi de: %f segundos \n", deltaTempoNatural4);

            // Tempo do Pior Caso:
            // Isso significa que os valores no vetor est�o em ordem decrescente, come�ando com "tamanhoVetor" na primeira posi��o e terminando com "1" na �ltima posi��o
            int *vetorPiorCaso4 = (int *)malloc(tamanhoVetor * sizeof(int));
            for (int i = 0; i <= tamanhoVetor; i++) {
                vetorPiorCaso4[i] = tamanhoVetor - i;
            }

            // Mede o tempo de execu��o do algoritmo para o pior caso
            gettimeofday(&tempo_inicial, NULL);
            insertionSort(vetorPiorCaso4, tamanhoVetor);
            gettimeofday(&tempo_final, NULL);

            // Calcula o tempo decorrido
            double deltaTempoPior4 = (tempo_final.tv_sec + tempo_final.tv_usec / 1000000.0) - (tempo_inicial.tv_sec + tempo_inicial.tv_usec / 1000000.0); // Faz o calculo para deixar em segundos
            printf("Tempo do pior caso do algoritmo foi de: %f segundos \n", deltaTempoPior4);

            // Libera a mem�ria alocada para os vetores
            free(vetorNatural4);
            free(vetorPiorCaso4);

            break;
        case 5:
            // Algoritmo HeapSort
            for (int j = 0; j < 10; j++) {
                int *vetor = (int *)malloc(tamanhoVetor * sizeof(int));

                // Preenche o vetor com valores aleat�rios
                srand(time(NULL) + j); // Adiciona um valor diferente � seed do srand
                for (int i = 0; i < tamanhoVetor; i++) {
                    vetor[i] = rand() % 100;
                }

                // HeapSort no vetor e contando o tempo
                gettimeofday(&tempo_inicial, NULL);
                heapSort(vetor, tamanhoVetor);
                gettimeofday(&tempo_final, NULL);

                // Somando os 10 tempos
                double deltaTempo = (tempo_final.tv_sec + tempo_final.tv_usec / 1000000.0) - (tempo_inicial.tv_sec + tempo_inicial.tv_usec / 1000000.0); // Faz o calculo para deixar em segundos
                somaDeltaTempo += deltaTempo;

                free(vetor);
            }
            // Realizando a media dos 10 tempos
            mediaDeltaTempo = somaDeltaTempo / 10.0;
            printf("Media de tempo de execucao do algoritmo foi de: %f segundos \n", mediaDeltaTempo);

            // Tempo do Comportamento Natural
            int *vetorNatural5 = (int *)malloc(tamanhoVetor * sizeof(int));
            for (int i = 0; i <= tamanhoVetor; i++) {
                vetorNatural5[i] = i;
            }

            // Mede o tempo de execu��o do algoritmo para o comportamento natural
            gettimeofday(&tempo_inicial, NULL);
            heapSort(vetorNatural5, tamanhoVetor);
            gettimeofday(&tempo_final, NULL);

            // Calcula o tempo decorrido
            double deltaTempoNatural5 = (tempo_final.tv_sec + tempo_final.tv_usec / 1000000.0) - (tempo_inicial.tv_sec + tempo_inicial.tv_usec / 1000000.0); // Faz o calculo para deixar em segundos
            printf("Tempo do comportamento natural do algoritmo foi de: %f segundos \n", deltaTempoNatural5);

            // Tempo do Pior Caso:
            // Isso significa que os valores no vetor est�o em ordem decrescente, come�ando com "tamanhoVetor" na primeira posi��o e terminando com "1" na �ltima posi��o
            int *vetorPiorCaso5 = (int *)malloc(tamanhoVetor * sizeof(int));
            for (int i = 0; i <= tamanhoVetor; i++) {
                vetorPiorCaso5[i] = tamanhoVetor - i;
            }

            // Mede o tempo de execucao do algoritmo para o pior caso
            gettimeofday(&tempo_inicial, NULL);
            heapSort(vetorPiorCaso5, tamanhoVetor);
            gettimeofday(&tempo_final, NULL);

            // Calcula o tempo decorrido
            double deltaTempoPior5 = (tempo_final.tv_sec + tempo_final.tv_usec / 1000000.0) - (tempo_inicial.tv_sec + tempo_inicial.tv_usec / 1000000.0); // Faz o calculo para deixar em segundos
            printf("Tempo do pior caso do algoritmo foi de: %f segundos \n", deltaTempoPior5);

            // Libera a mem�ria alocada para os vetores
            free(vetorNatural5);
            free(vetorPiorCaso5);

            break;
        case 6:
            // Algoritmo BubbleSort
            for (int j = 0; j < 10; j++) {
                int *vetor = (int *)malloc(tamanhoVetor * sizeof(int));

                // Preenche o vetor com valores aleat�rios
                srand(time(NULL) + j); // Adiciona um valor diferente � seed do srand
                for (int i = 0; i < tamanhoVetor; i++) {
                    vetor[i] = rand() % 100;
                }

                // BubbleSort no vetor e contando o tempo
                gettimeofday(&tempo_inicial, NULL);
                bubbleSort(vetor, tamanhoVetor);
                gettimeofday(&tempo_final, NULL);

                // Somando os 10 tempos
                double deltaTempo = (tempo_final.tv_sec + tempo_final.tv_usec / 1000000.0) - (tempo_inicial.tv_sec + tempo_inicial.tv_usec / 1000000.0); // Faz o calculo para deixar em segundos
                somaDeltaTempo += deltaTempo;

                free(vetor);
            }
            // Realizando a m�dia dos 10 tempos
            mediaDeltaTempo = somaDeltaTempo / 10.0;
            printf("Media de tempo de execucao do algoritmo foi de: %f segundos \n", mediaDeltaTempo);

            // Tempo do Comportamento Natural
            int *vetorNatural6 = (int *)malloc(tamanhoVetor * sizeof(int));
            for (int i = 0; i <= tamanhoVetor; i++) {
                vetorNatural6[i] = i;
            }

            // Mede o tempo de execu��o do algoritmo para o comportamento natural
            gettimeofday(&tempo_inicial, NULL);
            bubbleSort(vetorNatural6, tamanhoVetor);
            gettimeofday(&tempo_final, NULL);

            // Calcula o tempo decorrido
            double deltaTempoNatural6 = (tempo_final.tv_sec + tempo_final.tv_usec / 1000000.0) - (tempo_inicial.tv_sec + tempo_inicial.tv_usec / 1000000.0); // Faz o calculo para deixar em segundos
            printf("Tempo do comportamento natural do algoritmo foi de: %f segundos \n", deltaTempoNatural6);

            // Tempo do Pior Caso:
            // Isso significa que os valores no vetor est�o em ordem decrescente, come�ando com "tamanhoVetor" na primeira posi��o e terminando com "1" na �ltima posi��o
            int *vetorPiorCaso6 = (int *)malloc(tamanhoVetor * sizeof(int));
            for (int i = 0; i <= tamanhoVetor; i++) {
                vetorPiorCaso6[i] = tamanhoVetor - i;
            }

            // Mede o tempo de execu��o do algoritmo para o pior caso
            gettimeofday(&tempo_inicial, NULL);
            bubbleSort(vetorPiorCaso6, tamanhoVetor);
            gettimeofday(&tempo_final, NULL);

            // Calcula o tempo decorrido
            double deltaTempoPior6 = (tempo_final.tv_sec + tempo_final.tv_usec / 1000000.0) - (tempo_inicial.tv_sec + tempo_inicial.tv_usec / 1000000.0); // Faz o calculo para deixar em segundos
            printf("Tempo do pior caso do algoritmo foi de: %f segundos \n", deltaTempoPior6);

            // Libera a mem�ria alocada para os vetores
            free(vetorNatural6);
            free(vetorPiorCaso6);

            break;
        case 7:
            // Algoritmo ShellSort
            for (int j = 0; j < 10; j++) {
                int *vetor = (int *)malloc(tamanhoVetor * sizeof(int));

                // Preenche o vetor com valores aleat�rios
                srand(time(NULL) + j); // Adiciona um valor diferente � seed do srand
                for (int i = 0; i < tamanhoVetor; i++) {
                    vetor[i] = rand() % 100;
                }

                // ShellSort no vetor e contando o tempo
                gettimeofday(&tempo_inicial, NULL);
                shellSort(vetor, tamanhoVetor);
                gettimeofday(&tempo_final, NULL);

                // Somando os 10 tempos
                double deltaTempo = (tempo_final.tv_sec + tempo_final.tv_usec / 1000000.0) - (tempo_inicial.tv_sec + tempo_inicial.tv_usec / 1000000.0); // Faz o calculo para deixar em segundos
                somaDeltaTempo += deltaTempo;

                free(vetor);
            }
            // Realizando a m�dia dos 10 tempos
            mediaDeltaTempo = somaDeltaTempo / 10.0;
            printf("Media de tempo de execucao do algoritmo foi de: %f segundos \n", mediaDeltaTempo);

            // Tempo do Comportamento Natural
            int *vetorNatural7 = (int *)malloc(tamanhoVetor * sizeof(int));
            for (int i = 0; i <= tamanhoVetor; i++) {
                vetorNatural7[i] = i;
            }

            // Mede o tempo de execu��o do algoritmo para o comportamento natural
            gettimeofday(&tempo_inicial, NULL);
            shellSort(vetorNatural7, tamanhoVetor);
            gettimeofday(&tempo_final, NULL);

            // Calcula o tempo decorrido
            double deltaTempoNatural7 = (tempo_final.tv_sec + tempo_final.tv_usec / 1000000.0) - (tempo_inicial.tv_sec + tempo_inicial.tv_usec / 1000000.0); // Faz o calculo para deixar em segundos
            printf("Tempo do comportamento natural do algoritmo foi de: %f segundos \n", deltaTempoNatural7);

            // Tempo do Pior Caso:
            // Isso significa que os valores no vetor est�o em ordem decrescente, come�ando com "tamanhoVetor" na primeira posi��o e terminando com "1" na �ltima posi��o
            int *vetorPiorCaso7 = (int *)malloc(tamanhoVetor * sizeof(int));
            for (int i = 0; i <= tamanhoVetor; i++) {
                vetorPiorCaso7[i] = tamanhoVetor - i;
            }

            // Mede o tempo de execu��o do algoritmo para o pior caso
            gettimeofday(&tempo_inicial, NULL);
            shellSort(vetorPiorCaso7, tamanhoVetor);
            gettimeofday(&tempo_final, NULL);

            // Calcula o tempo decorrido
            double deltaTempoPior7 = (tempo_final.tv_sec + tempo_final.tv_usec / 1000000.0) - (tempo_inicial.tv_sec + tempo_inicial.tv_usec / 1000000.0); // Faz o calculo para deixar em segundos
            printf("Tempo do pior caso do algoritmo foi de: %f segundos \n", deltaTempoPior7);

            // Libera a mem�ria alocada para os vetores
            free(vetorNatural7);
            free(vetorPiorCaso7);

            break;
        case 8:
            // Algoritmo TimSort
            for (int j = 0; j < 10; j++) {
                int *vetor = (int *)malloc(tamanhoVetor * sizeof(int));

                // Preenche o vetor com valores aleat�rios
                srand(time(NULL) + j); // Adiciona um valor diferente � seed do srand
                for (int i = 0; i < tamanhoVetor; i++) {
                    vetor[i] = rand() % 100;
                }

                // TimSort no vetor e contando o tempo
                gettimeofday(&tempo_inicial, NULL);
                timSort(vetor, tamanhoVetor);
                gettimeofday(&tempo_final, NULL);

                // Somando os 10 tempos
                double deltaTempo = (tempo_final.tv_sec + tempo_final.tv_usec / 1000000.0) - (tempo_inicial.tv_sec + tempo_inicial.tv_usec / 1000000.0); // Faz o calculo para deixar em segundos
                somaDeltaTempo += deltaTempo;

                free(vetor);
            }
            // Realizando a m�dia dos 10 tempos
            mediaDeltaTempo = somaDeltaTempo / 10.0;
            printf("Media de tempo de execucao do algoritmo foi de: %f segundos \n", mediaDeltaTempo);

            // Tempo do Comportamento Natural
            int *vetorNatural8 = (int *)malloc(tamanhoVetor * sizeof(int));
            for (int i = 0; i <= tamanhoVetor; i++) {
                vetorNatural8[i] = i;
            }

            // Mede o tempo de execu��o do algoritmo para o comportamento natural
            gettimeofday(&tempo_inicial, NULL);
            timSort(vetorNatural8, tamanhoVetor);
            gettimeofday(&tempo_final, NULL);

            // Calcula o tempo decorrido
            double deltaTempoNatural8 = (tempo_final.tv_sec + tempo_final.tv_usec / 1000000.0) - (tempo_inicial.tv_sec + tempo_inicial.tv_usec / 1000000.0); // Faz o calculo para deixar em segundos
            printf("Tempo do comportamento natural do algoritmo foi de: %f segundos \n", deltaTempoNatural8);

            // Tempo do Pior Caso:
            // Isso significa que os valores no vetor est�o em ordem decrescente, come�ando com "tamanhoVetor" na primeira posi��o e terminando com "1" na �ltima posi��o
            int *vetorPiorCaso8 = (int *)malloc(tamanhoVetor * sizeof(int));
            for (int i = 0; i <= tamanhoVetor; i++) {
                vetorPiorCaso8[i] = tamanhoVetor - i;
            }

            // Mede o tempo de execu��o do algoritmo para o pior caso
            gettimeofday(&tempo_inicial, NULL);
            timSort(vetorPiorCaso8, tamanhoVetor);
            gettimeofday(&tempo_final, NULL);

            // Calcula o tempo decorrido
            double deltaTempoPior8 = (tempo_final.tv_sec + tempo_final.tv_usec / 1000000.0) - (tempo_inicial.tv_sec + tempo_inicial.tv_usec / 1000000.0); // Faz o calculo para deixar em segundos
            printf("Tempo do pior caso do algoritmo foi de: %f segundos \n", deltaTempoPior8);

            // Libera a mem�ria alocada para os vetores
            free(vetorNatural8);
            free(vetorPiorCaso8);

            break;
        case 9:
            // Algoritmo RadixSort
            for (int j = 0; j < 10; j++) {
                int *vetor = (int *)malloc(tamanhoVetor * sizeof(int));

                // Preenche o vetor com valores aleat�rios
                srand(time(NULL) + j); // Adiciona um valor diferente � seed do srand
                for (int i = 0; i < tamanhoVetor; i++) {
                    vetor[i] = rand() % 100;
                }

                // RadixSort no vetor e contando o tempo
                gettimeofday(&tempo_inicial, NULL);
                radix_sort(vetor, tamanhoVetor);
                gettimeofday(&tempo_final, NULL);

                // Somando os 10 tempos
                double deltaTempo = (tempo_final.tv_sec + tempo_final.tv_usec / 1000000.0) - (tempo_inicial.tv_sec + tempo_inicial.tv_usec / 1000000.0); // Faz o calculo para deixar em segundos
                somaDeltaTempo += deltaTempo;

                free(vetor);
            }
            // Realizando a m�dia dos 10 tempos
            mediaDeltaTempo = somaDeltaTempo / 10.0;
            printf("Media de tempo de execucao do algoritmo foi de: %f segundos \n", mediaDeltaTempo);

            // Tempo do Comportamento Natural
            int *vetorNatural9 = (int *)malloc(tamanhoVetor * sizeof(int));
            for (int i = 0; i <= tamanhoVetor; i++) {
                vetorNatural9[i] = i;
            }

            // Mede o tempo de execu��o do algoritmo para o comportamento natural
            gettimeofday(&tempo_inicial, NULL);
            radix_sort(vetorNatural9, tamanhoVetor);
            gettimeofday(&tempo_final, NULL);

            // Calcula o tempo decorrido
            double deltaTempoNatural9 = (tempo_final.tv_sec + tempo_final.tv_usec / 1000000.0) - (tempo_inicial.tv_sec + tempo_inicial.tv_usec / 1000000.0); // Faz o calculo para deixar em segundos
            printf("Tempo do comportamento natural do algoritmo foi de: %f segundos \n", deltaTempoNatural9);

            // Tempo do Pior Caso:
            // Isso significa que os valores no vetor est�o em ordem decrescente, come�ando com "tamanhoVetor" na primeira posi��o e terminando com "1" na �ltima posi��o
            int *vetorPiorCaso9 = (int *)malloc(tamanhoVetor * sizeof(int));
            for (int i = 0; i <= tamanhoVetor; i++) {
                vetorPiorCaso9[i] = tamanhoVetor - i;
            }

            // Mede o tempo de execu��o do algoritmo para o pior caso
            gettimeofday(&tempo_inicial, NULL);
            radix_sort(vetorPiorCaso9, tamanhoVetor);
            gettimeofday(&tempo_final, NULL);

            // Calcula o tempo decorrido
            double deltaTempoPior9 = (tempo_final.tv_sec + tempo_final.tv_usec / 1000000.0) - (tempo_inicial.tv_sec + tempo_inicial.tv_usec / 1000000.0); // Faz o calculo para deixar em segundos
            printf("Tempo do pior caso do algoritmo foi de: %f segundos \n", deltaTempoPior9);

            // Libera a mem�ria alocada para os vetores
            free(vetorNatural9);
            free(vetorPiorCaso9);

            break;
        default:
            printf("Escolha invalida\n");
            return 1;

        }
        printf("\nDeseja um novo teste?\nsim = 1 nao = 2\n");//loop para utilizacao do menu

        scanf("%d", &teste);

    } while (teste == 1);
         system("cls");
    return 0;
}
