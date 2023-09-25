#include <stdio.h>
#include <string.h>

#define TAMALFABETO 256

int BMH(char *T, char *P)
{
  int j, k;
  int n = strlen(T);
  int m = strlen(P);
  int alfabeto[TAMALFABETO];
  int count = 0;
  printf("BMH\n");

  // pré-processamento
  for (j = 0; j < TAMALFABETO; j++)
  {
    alfabeto[j] = m;
  }

  for (j = 1; j < m; j++)
  {
    alfabeto[P[j-1]] = m - j;
    printf("Alfabeto[%d = %c] -> %d\n", P[j-1], P[j-1], m - j);
  }

  int i = m - 1;
  // busca
  while (i <= n)
  {
    k = i;
    j = m - 1;
    while (j > 0 && T[k] == P[j])
    {
      printf("P[%d] = %c == T[%d] = %c\n", j, P[j], k, T[k]);
      k--;
      j--;
      count++;
    }
    printf("\n");

    if (j > 0 && T[k] != P[j])
    {
      printf("P[%d] = %c != T[%d] = %c\n", j, P[j], k, T[k]);
      count++;
    }

    if (j == 0)
    {
      count++;
      printf("P[%d] = %c == T[%d] = %c\n", j, P[j], k, T[k]);
      printf("\nComp = %d\n", count);
      return k;
    }

    i += alfabeto[T[i]];
  }
  return -1;
}

int main()
{
  char texto[] = "aabcaccacbac";
  char padrao[] = "cacbac";

  int index = BMH(texto, padrao);
  printf("Casamento na posicao: %d \n", index);

  for (int i = 0; i < strlen(padrao); i++)
  {
    printf("%c", texto[index]);
    index++;
  }
  return 0;
}
