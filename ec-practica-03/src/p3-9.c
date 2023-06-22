#include <stdio.h>
int main() {
  int n1, n2, counter = 0;

  do {
    printf("Introduce el primer numero: ");
    scanf("%d", &n1);

    printf("Introduce el segundo numero: ");
    scanf("%d", &n2);

    if (n1 > n2) {
      printf("%d no es menor que %d\n", n1, n2);
    }
  } while (n1 > n2);

  for (int i = n2; i >= n1; i--) {
    if ((i % 2) == 0) {
      if (counter == 0) {
        printf("%d", i);
        counter += 1;
      } else {
        printf(", %d", i);
      }
    }
  }

  return 0;
}