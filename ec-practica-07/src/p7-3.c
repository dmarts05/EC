#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void invierte(char *cadena, char *cadena_invertida);

int main() {
  char *cadena, *cadena_invertida;

  cadena = (char *)malloc(sizeof(char) * 101);
  cadena_invertida = (char *)malloc(sizeof(char) * 101);

  printf("Introduce una cadena de caracteres: ");
  fgets(cadena, 101, stdin);

  // Removemos el salto de línea que fgets inserta en el String que pasamos por
  // teclado.
  cadena[strcspn(cadena, "\n")] = 0;

  invierte(cadena, cadena_invertida);

  printf("%s", cadena_invertida);

  free(cadena);
  free(cadena_invertida);
  return 0;
}

void invierte(char *cadena, char *cadena_invertida) {
  for (int i = 0; i < strlen(cadena); i++) {
    cadena_invertida[strlen(cadena) - 1 - i] = cadena[i];
  }
}