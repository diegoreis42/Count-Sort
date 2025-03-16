#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "sorting.h"

int main()
{
  char *arq[] = {"../rand_files/100.txt", "../rand_files/1_000.txt", "../rand_files/10_000.txt", "../rand_files/100_000.txt", "../rand_files/1_000_000.txt"};
  char *vets[] = {"../ordered_vectors/counting/100Ord.txt", "../ordered_vectors/counting/1_000Ord.txt", "../ordered_vectors/counting/10_000Ord.txt", "../ordered_vectors/counting/100_000Ord.txt", "../ordered_vectors/counting/1_000_000Ord.txt"};
  int Tamanho;
  int trc;
  int cmp;
  trc = cmp = 0;
  FILE *m = fopen("../stats/count_stats.txt", "a+");
  if (m == NULL)
    return -1;

  printf("CountSort\n-------------------\nSorting...");

  for (int i = 0; i < 5; i++)
  {
    int *v = read_file(arq[i], &Tamanho);
    count_sort(v, (int)pow(10, (2 + i)), &trc, &cmp);
    print_file(vets[i], Tamanho, v);
    fprintf(m, "%d elements\n", (int)pow(10, (2 + i)));
    fprintf(m, "Swaps: %d\n", trc);
    fprintf(m, "Comparations: %d\n", cmp);
  }

  fclose(m);
  return 0;
}
