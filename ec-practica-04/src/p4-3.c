#include <stdio.h>
int potencia(int base, int exponent);

int main() {
  int base, exponent, result;
  do {
    printf("Escribe un número (base): ");
    scanf("%d", &base);
    printf("Escribe un número (exponente): ");
    scanf("%d", &exponent);

    if (base < 1 || exponent < 1) {
      printf("Los numeros deben ser positivos, por favor, vuelva a "
             "introducirlos.\n");
    }
  } while (base < 1 || exponent < 1);

  result = potencia(base, exponent);

  printf("La potencia es: %d", result);

  return 0;
}

int potencia(int base, int exponent) {
  int result = 1;

  for (int i = exponent; i >= 1; i--) {
    result = result * base;
    exponent = exponent - 1;
  }

  return result;
}
