// El algoritmo en pseudocódigo sería
// ALGORITMO ConvierteCelsiusAFarenheit
//  ENTRADAS:
//    grados_celsius: Real ; Grados Celsius
//  SALIDAS:
//    grados_farenheit: Real ; Grados Farenheit
//  VARIABLES:
//    grados_celsius: Real ;
//    grados_farenheit: Real ;
//  INICIO
//    LEA grados_celsius
//    grados_farenheit ← grados_celsius * 9/5 + 32
//    ESCRIBA “Los grados farenheit son: “
//    ESCRIBA grados_farenheit
//  FIN

// Librería que contiene las funciones scanf y printf
#include <stdio.h>

// Función principal del programa
int main() {
  // Este programa convierte los grados celsius leídos en grados farenheit
  // mostrando el resultado por pantalla
  // Declaro las variables de mi función
  float grados_celsius;
  float grados_farenheit;
  // Sustituyo la función LEA grados_celsius
  // Guarda el número leído en la variable grados_celsius
  scanf("%f", &grados_celsius);
  // Convierto los grados celsius a farenheit. Pongo 9.0 para que coja el
  // resultado real de dividir 9 entre 5:
  grados_farenheit = grados_celsius * (9.0 / 5) + 32;
  // Si no lo convierto a real me daría de resultado 1 en vez de 1.8

  // Imprimo los resultados
  printf("Los grados farenheit son: %.2f", grados_farenheit);

  // Fin del programa
  return 0;
}
