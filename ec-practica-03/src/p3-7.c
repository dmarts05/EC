#include <math.h>
#include <stdio.h>
int main() {
  int option;
  float result, radius, height, side1, side2;

  printf("Volumen cono (1)\nVolumen ortoedro (2)\n");
  scanf("%d", &option);

  switch (option) {
  case 1:
    printf("Introduce el valor del radio del cono: ");
    scanf("%f", &radius);

    printf("Introduce el valor de la altura del cono: ");
    scanf("%f", &height);

    result = (1.0 / 3) * M_PI * (radius * radius) * height;
    break;
  case 2:
    printf("Introduce el valor del lado 1 del ortoedro: ");
    scanf("%f", &side1);

    printf("Introduce el valor del lado 2 del ortoedro: ");
    scanf("%f", &side2);

    printf("Introduce el valor de la altura del ortoedro: ");
    scanf("%f", &height);

    result = side1 * side2 * height;
    break;
  default:
    printf("Opcion erronea");
    break;
  }

  if (option == 1 || option == 2) {
    printf("Resultado: %.2f\n", result);
  }

  return 0;
}