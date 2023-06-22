#include <stdio.h>
#include <stdlib.h>

int calculamaximo(int *p, int n);

int main() {
  int *p, n, result;

  printf("Introduce cuántos enteros vas a almacenar: ");
  scanf("%d", &n);
  p = (int*) malloc(n*sizeof(int));

  for (int i = 0; i < n; i++) {
    printf("Introduce el entero %d: ", (i + 1));
    scanf("%d", p + i);
  }

  result = calculamaximo(p, n);

  printf("Máximo: %d\n", result);

  for (int i = 0; i < n; i++) {
    printf("Número leído %d: %d\n", (i + 1), *(p + i));
  }

  free(p);
  return 0;
}

int calculamaximo(int *p, int n) {
  int max = 0;

  for (int i = 0; i < n; i++) {
    if (max < *(p + i)) {
      max = *(p + i);
    }
  }

  return max;
}