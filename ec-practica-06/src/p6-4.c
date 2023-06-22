#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init_matrix(int *matrix, int size);
void imprime(int *matrix, int size);
void multiplica(int *matrix1, int *matrix2, int *result, int size);

int main() {
  // srand(time(NULL));
  int *matrix1, *matrix2, *result, size;

  printf("Introduce el tamaño de la matriz: ");
  scanf(" %d", &size);

  matrix1 = (int*) malloc(sizeof(int) * size * size);
  matrix2 = (int*) malloc(sizeof(int) * size * size);
  result = (int*) malloc(sizeof(int) * size * size);

  init_matrix(matrix1, size);
  imprime(matrix1, size);
  printf("\n");

  init_matrix(matrix2, size);
  imprime(matrix2, size);
  printf("\n");

  multiplica(matrix1, matrix2, result, size);
  imprime(result, size);

  free(matrix1);
  free(matrix2);
  free(result);
  return 0;
}

void init_matrix(int *m, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      *(m + (i * size) + j) = (rand() % 10) + 1;
    }
  }
}

void imprime(int *matrix, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (j == (size - 1)) {
        printf("[%d]\n", *(matrix + (i * size) + j));
      } else {
        printf("[%d]", *(matrix + (i * size) + j));
      }
    }
  }
}

void multiplica(int *matrix1, int *matrix2, int *result, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      *(result + (i * size) + j) = 0;
    }
  }

  for (int i = 0; i < size; ++i) {
      for (int j = 0; j < size; ++j) {
         for (int k = 0; k < size; ++k) {
           *(result + (i * size) + j) += *(matrix1 + (i * size) + k) * *(matrix2 + (k * size) + j);
         }
      }
   }
}