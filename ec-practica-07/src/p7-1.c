#include <stdio.h>
#include <string.h>

int main() {
  char cadena[101];
  char compara[8] = "compara";
  char anadida[8] = "anadida";

  printf("Introduce una cadena de caracteres: ");
  fgets(cadena, 101, stdin);

  // Removemos el salto de línea que fgets inserta en el String que pasamos por
  // teclado.
  cadena[strcspn(cadena, "\n")] = 0;

  int longitud = strlen(cadena);

  printf("Longitud de la cadena: %d\n", longitud);

  if (strcmp(cadena, compara) == 0) {
    printf("Es igual a la cadena compara\n");
  } else {
    printf("Es distinta a la cadena compara\n");
  }

  strcat(cadena, anadida);
  printf("Las cadenas concatenadas son: %s", cadena);

  return 0;
}