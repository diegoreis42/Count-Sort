#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "sorting.h"

int *read_file(char *nomeArquivo, int *Tamanho)
{
    FILE *arq;
    int *vet = NULL;
    int num, i = 0;

    arq = fopen(nomeArquivo, "r");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return NULL;
    }

    while (fscanf(arq, "%d", &num) == 1)
    {
        vet = (int *)realloc(vet, (i + 1) * sizeof(int));
        vet[i] = num;
        i++;
    }

    fclose(arq);

    if (i == 0)
    {
        free(vet);
        return NULL;
    }

    *Tamanho = i;
    return vet;
}

int print_file(char *nomeSaida, int qtd, int *vet)
{

    FILE *fptr;

    fptr = fopen(nomeSaida, "w");
    if (fptr == NULL)
        return -1;

    for (int i = 0; i < qtd; i++)
    {
        fprintf(fptr, "%d\n", vet[i]);
    }

    fclose(fptr);
    return 1;
}

int *insertion_sort(int *v, int tamanho, int *trc, int *cmp)
{
    int marcador;
    int aux;
    int pos;
    for (marcador = 1; marcador < tamanho; marcador++)
    {
        pos = marcador - 1;

        aux = v[marcador];
        while (aux < v[pos] && pos >= 0)
        {

            *cmp += 1;
            v[pos + 1] = v[pos];
            pos = pos - 1;
        }
        v[pos + 1] = aux;
    }
    return v;
}

void mergesort(int *v, int inicio, int fim, int *trc, int *cmp)
{
    if (inicio < fim)
    {
        int meio = (inicio + fim) / 2;
        mergesort(v, inicio, meio, trc, cmp);
        mergesort(v, meio + 1, fim, trc, cmp);
        merge(v, inicio, meio, fim, trc, cmp);
    }
}

void merge(int *v, int inicio, int meio, int fim, int *trc, int *cmp)
{
    int tam = fim - inicio + 1;
    int *vetAux = (int *)malloc(tam * sizeof(int));
    int i, j, k;
    for (i = inicio; i <= fim; i++)
        vetAux[i - inicio] = v[i];
    i = 0;
    j = meio - inicio + 1;
    k = inicio;
    while (i <= meio - inicio && j <= fim - inicio)
    {
        *cmp += 1;
        if (vetAux[i] <= vetAux[j])
        {
            v[k] = vetAux[i];
            i++;
        }
        else
        {
            v[k] = vetAux[j];
            j++;
        }
        k++;
    }
    while (i <= meio - inicio)
    {
        *trc += 1;
        v[k] = vetAux[i];
        i++;
        k++;
    }
    while (j <= fim - inicio)
    {
        *trc += 1;
        v[k] = vetAux[j];
        j++;
        k++;
    }
    free(vetAux);
}

int median(int a, int b, int c)
{
    if ((a <= b && b <= c) || (c <= b && b <= a))
    {
        return b;
    }
    else if ((b <= a && a <= c) || (c <= a && a <= b))
    {
        return a;
    }
    else
    {
        return c;
    }
}

void quick(int *v, int esq, int dir, int tam, int *trc, int *cmp)
{

    if (tam > 1)
    {
        int meio = (esq + dir) / 2;
        int pv = median(v[esq], v[meio], v[dir]);
        int i, j;
        i = esq;
        j = dir;
        int aux;

        while (i <= j)
        {
            while (v[i] < pv)
            {
                i++;
                *cmp += 1;
            }
            while (v[j] > pv)
            {
                j--;
                *cmp += 1;
            }
            if (i <= j)
            {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
                i++;
                j--;
                *trc += 1;
            }
        }

        quick(v, esq, j, j - esq + 1, trc, cmp);
        quick(v, i, dir, dir - i + 1, trc, cmp);
    }
}

int *randVector(int tamanho)
{
    int j;
    srand(time(NULL));
    int *v = (int *)malloc(sizeof(int) * tamanho);

    for (int i = 0; i < tamanho; i++)
        v[i] = -1;

    for (int i = 0; i < tamanho; i++)
    {
        j = rand() % tamanho;
        while (v[j] != -1)
        {
            if (j < tamanho)
            {
                j++;
            }
            else
            {
                j = 0;
            }
        }
        v[j] = i;
    }
    return v;
}

void count_sort(int arr[], int n, int *trc, int *cmp)
{
    int i, j, max = arr[0], *count_arr, *sorted_arr;

    for (i = 1; i < n; i++)
    {
        *cmp += 1;
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    count_arr = (int *)calloc(max + 1, sizeof(int));
    sorted_arr = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        count_arr[arr[i]]++;
    }

    for (i = 1; i <= max; i++)
    {
        count_arr[i] += count_arr[i - 1];
    }

    for (i = n - 1; i >= 0; i--)
    {
        *trc += 1;
        sorted_arr[count_arr[arr[i]] - 1] = arr[i];
        count_arr[arr[i]]--;
    }

    for (i = 0; i < n; i++)
    {
        arr[i] = sorted_arr[i];
    }

    free(count_arr);
    free(sorted_arr);
}
