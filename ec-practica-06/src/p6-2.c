#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int calculaminimo(int *m, int r, int c);
void inicializamatriz(int *m, int r, int c);

int main() {
  // srand(time(NULL));
  int *m, r, c, result;

  printf("Introduce el número de filas: ");
  scanf(" %d", &r);
  printf("Introduce el número de columnas: ");
  scanf(" %d", &c);

  m = (int*) malloc(sizeof(int) * r * c);

  inicializamatriz(m, r, c);

  result = calculaminimo(m, r, c);

  printf("Mínimo: %d\n", result);

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      printf("[%d]", *(m + (i * c) + j));
    }

    printf("\n");
  }

  free(m);
  return 0;
}

int calculaminimo(int *m, int r, int c) {
  int min = *m;

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (min > *(m + (i * c) + j)) {
        min = *(m + (i * c) + j);
      }
    }
  }

  return min;
}

void inicializamatriz(int *m, int r, int c) {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      *(m + (i * c) + j) = (rand() % 10) + 1;
    }
  }
}