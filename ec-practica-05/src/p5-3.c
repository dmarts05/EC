#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VOCABSIZE 26
#define PASSSIZE 8

void init_arr(char arr[VOCABSIZE]);

int main() {
  // srand(time(NULL));
  char vocabulary[VOCABSIZE];
  char password[PASSSIZE + 1];
  password[PASSSIZE] = '\0';

  init_arr(vocabulary);

  for (int i = 0; i < PASSSIZE; i++) {
    password[i] = vocabulary[(rand() % 26)];
  }

  printf("%s", password);

  return 0;
}

void init_arr(char arr[VOCABSIZE]) {
  char temp[VOCABSIZE] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                   'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                   's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

  for (int i = 0; i < VOCABSIZE; i++) {
    arr[i] = temp[i];
  }
}