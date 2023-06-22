#define _GNU_SOURCE
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int init_matrix(char **students, FILE *pfile);
void print_matrix(char **students, int num_students);
void print_students(char **students, int num_studens, char letter);

int main() {
  char **students;
  FILE *pfile;
  char letter;
  int num_students;

  students = (char **)malloc(sizeof(char *) * 5);

  for (int i = 0; i < 5; i++) {
    *(students + i) = (char *)malloc(sizeof(char) * 101);
  }

  pfile = fopen("info.txt", "r");

  if (pfile == NULL) {
    fprintf(stderr, "Ha ocurrido un error al abrir el archivo");
    exit(EXIT_FAILURE);
  }

  num_students = init_matrix(students, pfile);
  fclose(pfile);

  printf("Introduce la inicial de un alumno: ");
  scanf("%c", &letter);
  letter = toupper(letter);
  print_students(students, num_students, letter);

  printf("\n");
  printf("\n");
  
  print_matrix(students, num_students);

  free(students);
  return 0;
}

int init_matrix(char **students, FILE *pfile) {
  char *line = NULL;
  size_t line_size = 0;
  int counter = 0;

  while ((getline(&line, &line_size, pfile) != -1)) {
    strcpy(*(students + counter), line);
    counter++;
  }

  free(line);
  return counter;
}

void print_matrix(char **students, int num_students) {
  for (int i = 0; i < num_students; i++) {
    printf("%s", *(students + i));
  }
}

void print_students(char **students, int num_studens, char letter) {
  for (int i = 0; i  < num_studens; i++) {
    if (*(*(students + i)) == letter) {
      printf("%s", *(students + i));
    }
  }
}