#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

void init_matrix(int matrix[SIZE][SIZE]);
void imprime(int matrix[SIZE][SIZE]);
void producto(int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE], int result[SIZE][SIZE]);

int main() {
  // srand(time(NULL));
  int matrix1[SIZE][SIZE];
  int matrix2[SIZE][SIZE];
  int result[SIZE][SIZE];

  init_matrix(matrix1);
  imprime(matrix1);
  printf("\n");
  init_matrix(matrix2);
  imprime(matrix2);
  printf("\n");

  producto(matrix1, matrix2, result);
  imprime(result);

  return 0;
}

void init_matrix(int matrix[SIZE][SIZE]) {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      matrix[i][j] = (rand() % 5) + 1;
    }
  }
}

void imprime(int matrix[SIZE][SIZE]) {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      if (j == (SIZE - 1)) {
        printf("[%d]\n", matrix[i][j]);
      } else {
        printf("[%d]", matrix[i][j]);
      }
    }
  }
}

void producto(int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE], int result[SIZE][SIZE]) {

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      result[i][j] = 0;
    }
  }

  for (int i = 0; i < SIZE; ++i) {
      for (int j = 0; j < SIZE; ++j) {
         for (int k = 0; k < SIZE; ++k) {
            result[i][j] += matrix1[i][k] * matrix2[k][j];
         }
      }
   }

}