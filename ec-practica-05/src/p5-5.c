#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 6

void init_matrix(int matrix[SIZE][SIZE]);
int suma(int matrix[SIZE][SIZE]);

int main() {
  // srand(time(NULL));
  int matrix[SIZE][SIZE];
  int result;

  init_matrix(matrix);
  result = suma(matrix);

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      if (j == (SIZE - 1)) {
        printf("[%d]\n", matrix[i][j]);
      } else {
        printf("[%d]", matrix[i][j]);
      }
    }
  }

  printf("\nSuma: %d", result);

  return 0;
}

void init_matrix(int matrix[SIZE][SIZE]) {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      matrix[i][j] = (rand() % 10) + 1;
    }
  }
}

int suma(int matrix[SIZE][SIZE]) {
  int result = 0;

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
     result += matrix[i][j];
    }
  }

  return result;
}