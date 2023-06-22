// Librería que contiene las funciones scanf y printf
#include <stdio.h>
// Función principal del programa
int main() {
  // Este programa calcula la suma de los primeros n números
  // Declaro las variables de mi función
  int num, total, i;
  // Sustituyo la función ESCRIBA "cadena" por printf
  printf("Escribe cuantos números quieres sumar: ");
  // Sustituyo la función LEA num por scanf (" %d", &variableEntera);
  scanf("%d", &num); // Guarda el número leído en la variable num
  // Inicializo las variables
  total = 0;
  i = 1;
  // Compruebo si el número introducido es mayor o igual que 1
  if (num >= 1) {
    // Hago el bucle para sumar hasta que i valga n
    // while (i <= num) {
    //   // Calculo la suma parcial
    //   total = total + i;
    //   i = i + 1;
    // }

    // do {
    //   // Calculo la suma parcial
    //   total = total + i;
    //   i = i + 1;
    // } while (i <= num);

    for (int i = 1; i <= num; i++) {
      total = total + i;
    }

    // Sustituyo la función ESCRIBA "cadena" por printf
    printf("La suma es: %d", total);
  } else {
    // Sustituyo la función ESCRIBA "cadena" por printf
    printf("El número ha de ser mayor o igual a 1");
  }
  // Fin del programa
  return 0;
}