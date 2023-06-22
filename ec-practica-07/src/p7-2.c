#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quitaespacios(char *cadena, char *cadenasin);
void quitarenterbuffer();

int main() {
  char *cadena, *cadenasin;
  int caracteres;

  printf("Introduce el número de caracteres de la cadena: ");
  scanf("%d", &caracteres);

  // Ajustamos la variable caracteres para que entre el número introducido
  caracteres++;

  // Removemos Enter del buffer para evitar un conflicto con fgets()
  quitarenterbuffer();
  // while (getchar() != ln) Alternativa

  cadena = (char *)malloc(sizeof(char) * caracteres);
  cadenasin = (char *)malloc(sizeof(char) * caracteres);

  printf("Introduce una cadena de caracteres: ");
  fgets(cadena, caracteres, stdin);

  // Removemos el salto de línea que fgets inserta en el String que pasamos por
  // teclado.
  cadena[strcspn(cadena, "\n")] = 0;

  quitaespacios(cadena, cadenasin);

  printf("%s", cadenasin);

  free(cadena);
  free(cadenasin);
  return 0;
}

void quitaespacios(char *cadena, char *cadenasin) {
  int sin_index = 0;

  for (int i = 0; i < strlen(cadena); i++) {
    if (cadena[i] == ' ') {
      continue;
    } else {
      cadenasin[sin_index] = cadena[i];
      sin_index++;
    }
  }
}

void quitarenterbuffer() {
  int c;

  do {
    c = getchar();
  } while(c != EOF && c != '\n');
}