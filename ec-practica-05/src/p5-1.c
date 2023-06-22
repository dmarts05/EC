#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void init_arr(int arr[]);
int suma(int arr[]);

int main() {
  // srand(time(NULL));
  int numbers[SIZE], result;

  init_arr(numbers);
  result = suma(numbers);

  for (int i = 0; i < SIZE; i++) {
    printf("Elemento %d: %d\n", (i + 1), numbers[i]);
  }

  printf("Resultado de la suma: %d", result);

  return 0;
}

void init_arr(int arr[]) {
  for (int i = 0; i < SIZE; i++) {
    arr[i] = (rand() % SIZE) + 1;
  }
}

int suma(int arr[]) {
  int result = 0;

  for (int i = 0; i < SIZE; i++) {
    result += arr[i];
  }

  return result;
}