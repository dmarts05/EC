// Librería que contiene las funciones scanf y printf
#include <stdio.h>
// Función principal del programa
int main() {
  // Este programa imprime por pantalla un número leído por teclado
  // Declaro las variables de mi función
  int num;
  // Sustituyo la función ESCRIBA "cadena" por printf
  printf("Escribe un número : ");
  // Sustituyo la función LEA Num por scanf (" %d", &variableEntera);
  scanf("%d", &num); // Guarda el número leído en la variable Num
  
  printf("El número introducido es: %d \nFin del algoritmo", num);
  // Fin del programa
  return 0;
}