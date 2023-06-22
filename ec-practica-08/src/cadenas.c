#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Error, el número de argumentos no es válido");
  } else {
    char cadena[101];

    printf("Introduce otra cadena de caracteres: ");
    fgets(cadena, 101, stdin);

    // Removemos el salto de línea que fgets inserta en el String que pasamos
    // por teclado.
    cadena[strcspn(cadena, "\n")] = '\0';

    int longitud = strlen(cadena);

    printf("Longitud de la cadena introducida por teclado: %d\n", longitud);

    strcat(cadena, "Cadena añadida");
    printf("Las cadenas concatenadas son: %s\n", cadena);

    if (strstr(cadena, argv[1])) {
      printf(
          "La cadena (%s) contiene a la cadena pasada como argumento (%s).\n",
          cadena, argv[1]);
    }

    printf("La letra que ocupa la posición especificada es: %c",
           cadena[atoi(argv[2]) - 1]);
  }

  return 0;
}