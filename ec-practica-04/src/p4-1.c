#include <stdio.h>
void calcula_nota(int mark);

int main() {
  int mark;
  printf("Escribe la nota numérica: ");
  scanf("%d", &mark);
  calcula_nota(mark);
  return 0;
}

void calcula_nota(int mark) {
  switch (mark) {
  case 5:
  case 6:
    printf("Aprobado\n");
    break;
  case 7:
  case 8:
    printf("Notable\n");
    break;
  case 9:
  case 10:
    printf("Sobresaliente\n");
    break;
  default:
    printf("Suspenso\n");
  }
}