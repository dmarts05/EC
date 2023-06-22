#include <stdio.h>
int factorial(int num);

int main() {
    int num, result;

    printf("Introduce un numero: ");
    scanf("%d", &num);

    result = factorial(num);

    printf("El resultado es: %d", result);

    return 0;
}

int factorial(int num) {
    int result = 1;

    for (int i = num; i > 0; i--) {
      result *= i;
    }

    return result;
}