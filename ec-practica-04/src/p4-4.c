#include <math.h>
#include <stdbool.h>
#include <stdio.h>
int menu();
float volumen_cono(float radius, float height);
float volumen_ortoedro(float side1, float side2, float height);

int main() {
  int option = menu();
  bool exit = false;
  float radius, height, side1, side2, result;

  switch (option) {
  case 1:
    printf("Introduce el valor del radio del cono: ");
    scanf("%f", &radius);

    printf("Introduce el valor de la altura del cono: ");
    scanf("%f", &height);

    result = volumen_cono(radius, height);
    break;
  case 2:
    printf("Introduce el valor del lado 1 del ortoedro: ");
    scanf("%f", &side1);

    printf("Introduce el valor del lado 2 del ortoedro: ");
    scanf("%f", &side2);

    printf("Introduce el valor de la altura del ortoedro: ");
    scanf("%f", &height);

    result = volumen_ortoedro(side1, side2, height);
    break;
  case 3:
    exit = true;
    break;
  }

  if (option == 1 || option == 2) {
    printf("Resultado: %.2f\n", result);
  }

  return 0;
}

int menu() {
  int option;

  while (true) {
    printf("Volumen cono (1)\nVolumen ortoedro (2)\nSalir (3)\n");
    scanf("%d", &option);

    switch (option) {
    case 1:
      return 1;
      break;
    case 2:
      return 2;
      break;
    case 3:
      return 3;
      break;

    default:
      printf("Opcion erronea\n");
      break;
    }
  }
}

float volumen_cono(float radius, float height) {
  return (1.0 / 3) * M_PI * (radius * radius) * height;
}

float volumen_ortoedro(float side1, float side2, float height) {
  return side1 * side2 * height;
}