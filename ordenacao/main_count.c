#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "ordenacao.h"

int main(){
    char *arq[]  = {"../rand_files/100.txt", "../rand_files/1_000.txt", "../rand_files/10_000.txt", "../rand_files/100_000.txt", "../rand_files/1_000_000.txt"};
    char *vets[] = {"../vetoresOrdenados/counting/100Ord.txt", "../vetoresOrdenados/counting/1_000Ord.txt", "../vetoresOrdenados/counting/10_000Ord.txt", "../vetoresOrdenados/counting/100_000Ord.txt", "../vetoresOrdenados/counting/1_000_000Ord.txt"};
    int Tamanho;
    int trc;
    int cmp;
    trc = cmp = 0;
    FILE *m = fopen("../stats/count_stats.txt", "a+");
    if(m == NULL)
      return -1;

printf("CountSort\n-------------------\nSorting...");
// executando merge para todos os arquivos de rand_files
    for(int i = 0; i < 5; i++){
      int *v = leArquivo(arq[i], &Tamanho);
      countSort(v, (int) pow(10, (2 + i)),&trc, &cmp);
      imprimeArquivo(vets[i],Tamanho, v);
      fprintf(m, "%d elementos\n", (int) pow(10, (2 + i)));
      fprintf(m,"Trocas: %d\n", trc);
      fprintf(m, "Comparações: %d\n", cmp);
    }

fclose(m);
return 0;
}
