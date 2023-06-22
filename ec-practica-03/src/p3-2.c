// Librería que contiene las funciones scanf y printf
#include <stdio.h>
// Función principal del programa
int main() {
  // Este programa convierte una nota numérica a su
  // calificación correspondiente
  // Declaro las variables de mi función
  int num;
  // Sustituyo la función ESCRIBA "cadena" por printf
  printf("Escribe la nota numérica: ");
  // Sustituyo la función LEA num por scanf (" %d", &variableEntera);
  scanf("%d", &num); // Guarda el número leído en la variable num
  // Compruebo qué nota es para imprimir la cadena correspondiente
  if ((num == 5) || (num == 6)) {
    // Sustituyo la función ESCRIBA "cadena" por printf
    printf("Aprobado");
  } else {
    if ((num == 7) || (num == 8)) {
      // Sustituyo la función ESCRIBA "cadena" por printf
      printf("Notable");
    } else {
      if ((num == 9) || (num == 10)) {
        // Sustituyo la función ESCRIBA "cadena" por printf
        printf("Sobresaliente");
      } else {
        // Sustituyo la función ESCRIBA "cadena" por printf
        printf("Suspenso");
      }
    }
  }
  // Fin del programa
  return 0;
}