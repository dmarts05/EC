#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMROWS 3
#define NUMCOLUMNS 6

void init_matrix(int matrix[NUMROWS][NUMCOLUMNS]);
void suma_columnas(int matrix[NUMROWS][NUMCOLUMNS], int result[NUMCOLUMNS]);

int main() {
  // srand(time(NULL));
  int matrix[NUMROWS][NUMCOLUMNS];
  int result[NUMCOLUMNS];

  init_matrix(matrix);
  suma_columnas(matrix, result);

  for (int i = 0; i < NUMROWS; i++) {
    for (int j = 0; j < NUMCOLUMNS; j++) {
      if (j == (NUMCOLUMNS - 1)) {
        printf("[%d]\n", matrix[i][j]);
      } else {
        printf("[%d]", matrix[i][j]);
      }
    }
  }

  printf("\n");

  for (int i; i < NUMCOLUMNS; i++) {
    printf("[%d]", result[i]);
  }

  return 0;
}

void init_matrix(int matrix[NUMROWS][NUMCOLUMNS]) {
  for (int i = 0; i < NUMROWS; i++) {
    for (int j = 0; j < NUMCOLUMNS; j++) {
      matrix[i][j] = (rand() % 10) + 1;
    }
  }
}

void suma_columnas(int matrix[NUMROWS][NUMCOLUMNS], int result[NUMCOLUMNS]) {

  for (int i = 0; i < NUMCOLUMNS; i++) {
    result[i] = 0;
  }

  for (int j = 0; j < NUMCOLUMNS; j++) {
    for (int i = 0; i < NUMROWS; i++) {
      result[j] += matrix[i][j];
    }
  }
}