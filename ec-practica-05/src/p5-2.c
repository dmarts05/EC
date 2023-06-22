#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 9

void init_matrix(int matrix[SIZE][SIZE]);

int main() {
  // srand(time(NULL));
  int matrix[SIZE][SIZE];

  init_matrix(matrix);
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      if (j == (SIZE - 1)) {
        printf("[%d]\n", matrix[i][j]);
      } else {
        printf("[%d]", matrix[i][j]);
      }
    }
  }

  return 0;
}

void init_matrix(int matrix[SIZE][SIZE]) {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      if (i == j) {
        matrix[i][j] = 1;
      } else {
        matrix[i][j] = 0;
      }
    }
  }
}