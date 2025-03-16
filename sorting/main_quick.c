#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "sorting.h"

int main()
{
  char *arq[] = {"../rand_files/100.txt", "../rand_files/1_000.txt", "../rand_files/10_000.txt", "../rand_files/100_000.txt", "../rand_files/1_000_000.txt"};
  char *vets[] = {"../ordered_vectors/quick/100Ord.txt", "../ordered_vectors/quick/1_000Ord.txt", "../ordered_vectors/quick/10_000Ord.txt", "../ordered_vectors/quick/100_000Ord.txt", "../ordered_vectors/quick/1_000_000Ord.txt"};
  int Tamanho;
  int trc;
  int cmp;
  trc = cmp = 0;
  FILE *f = fopen("../stats/quick_stats.txt", "a+");
  if (f == NULL)
    return -1;

  printf("QuickSort\n-------------------\nSorting...");

  for (int i = 0; i < 5; i++)
  {
    int *v = read_file(arq[i], &Tamanho);
    fprintf(f, "%d elements\n", (int)pow(10, (2 + i)));
    quick(v, 0, Tamanho - 1, Tamanho, &trc, &cmp);
    
    print_file(vets[i], (int)pow(10, (2 + i)), v);
    fprintf(f, "Swaps: %d\n", trc);
    fprintf(f, "Comparisions: %d\n", cmp);
    trc = cmp = 0;
  }

  fclose(f);
  return 0;
}
