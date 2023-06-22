#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void minimoFilas(int *m, int *p, int r, int c);

int main() {
  // srand(time(NULL));
  int *matrix, *p, r, c, result;

  printf("Introduce el número de filas: ");
  scanf(" %d", &r);
  printf("Introduce el número de columnas: ");
  scanf(" %d", &c);

  matrix = (int*) malloc(sizeof(int) * r * c);
  p = (int*) malloc(sizeof(int) * r);


  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      *(matrix + (i * c) + j) = (rand() % 21) - 10;
    }
  }

  minimoFilas(matrix, p, r, c);

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      printf("[%d]", *(matrix + (i * c) + j));
    }

    printf("\n");
  }

  printf("\n");

  for (int i = 0; i < r; i++) {
    printf("[%d]", *(p + i));
  }

  free(matrix);
  free(p);
  return 0;
}

void minimoFilas(int *m, int *p, int r, int c) {
  for (int i = 0; i < r; i++) {
    int min = *(m + (i * c));

    for (int j = 0; j < c; j++) {
      if (min > *(m + (i * c) + j)) {
        min = *(m + (i * c) + j);
      }
    }

    *(p + i) = min;
  }
}