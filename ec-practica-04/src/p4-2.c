#include <stdio.h>
int suma_n_primeros_nums(int num);

int main() {
  int num, result;
  do {
    printf("Escribe cuantos números quieres sumar: ");
    scanf("%d", &num);
    if (num < 1) {
      printf(
          "El numero debe ser positivo, por favor, vuelva a introducirlo.\n");
    }
  } while (num < 1);

  result = suma_n_primeros_nums(num);

  printf("La suma es: %d", result);

  return 0;
}

int suma_n_primeros_nums(int num) {
  int result = 0;

  for (int i = 1; i <= num; i++) {
    result = result + i;
  }

  return result;
}