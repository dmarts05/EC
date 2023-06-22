#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Talumno {
    char nombre[100];
    char apellido[100];
    float nota1;
    float nota2;
    float media;
};

int argumentos_validos(FILE *pfile);

int calcular_numero_alumnos(FILE *pfile);

void insertar_datos(FILE *pfile, struct Talumno *palumnos);

void calcular_medias(struct Talumno *palumnos, int num_alumnos);

void mejor_nota_media(struct Talumno *palumnos, int num_alumnos);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Error, el número de argumentos no es válido");
        exit(EXIT_FAILURE);
    }

    FILE *pfile;
    struct Talumno *palumnos;
    int num_alumnos;
    int arg_validos = 0;

    pfile = fopen(argv[1], "r");

    if (pfile == NULL) {
        fprintf(stderr, "Ha ocurrido un error al abrir el archivo");
        exit(EXIT_FAILURE);
    }

    arg_validos = argumentos_validos(pfile);

    if (arg_validos == 0) {
        fprintf(stderr, "Error, el número de argumentos del archivo no es válido");
        exit(EXIT_FAILURE);
    }

    rewind(pfile);

    num_alumnos = calcular_numero_alumnos(pfile);

    rewind(pfile);

    palumnos = (struct Talumno *) malloc(sizeof(struct Talumno) * num_alumnos);

    insertar_datos(pfile, palumnos);
    pclose(pfile);

    calcular_medias(palumnos, num_alumnos);

    mejor_nota_media(palumnos, num_alumnos);

    free(palumnos);
    return 0;
}

int argumentos_validos(FILE *pfile) {
    char *line = NULL;
    size_t line_size = 0;
    int arg_correcto = 5;
    int result = 1;

    while ((getline(&line, &line_size, pfile) != -1)) {
        int counter = 0;

        char line_str[100];
        strcpy(line_str, line);
        char *tokens = strtok(line_str, " ");

        while (tokens != NULL) {
            tokens = strtok(NULL, " ");
            counter++;
        }

        free(tokens);

        if (counter != arg_correcto) {
            result = 0;
        }
    }

    free(line);
    return result;
}

int calcular_numero_alumnos(FILE *pfile) {
    char *line = NULL;
    size_t line_size = 0;
    int num_alumnos = 0;

    while ((getline(&line, &line_size, pfile) != -1)) {
        num_alumnos++;
    }

    free(line);
    return num_alumnos;
}

void insertar_datos(FILE *pfile, struct Talumno *palumnos) {
    char *line = NULL;
    size_t line_size = 0;
    int counter = 0;

    while ((getline(&line, &line_size, pfile) != -1)) {
        char line_str[100];
        char token_str[100];
        strcpy(line_str, line);
        char *token = strtok(line_str, " ");
        strcpy(token_str, token);

        strcpy((palumnos + counter)->nombre, token_str);
        token = strtok(NULL, " ");
        strcpy(token_str, token);

        strcpy((palumnos + counter)->apellido, token_str);
        token = strtok(NULL, " ");
        strcpy(token_str, token);

        strcat((palumnos + counter)->apellido, " ");
        strcat((palumnos + counter)->apellido, token_str);
        token = strtok(NULL, " ");
        strcpy(token_str, token);

        (palumnos + counter)->nota1 = atof(token_str);
        token = strtok(NULL, " ");
        strcpy(token_str, token);

        (palumnos + counter)->nota2 = atof(token_str);
        token = strtok(NULL, " ");
        strcpy(token_str, token_str);

        free(token);
        counter++;
    }

    free(line);
}

void calcular_medias(struct Talumno *palumnos, int num_alumnos) {
    for (int i = 0; i < num_alumnos; i++) {
        float media = ((palumnos + i)->nota1 + (palumnos + i)->nota2) / 2.0;
        (palumnos + i)->media = media;
    }
}

void mejor_nota_media(struct Talumno *palumnos, int num_alumnos) {
    struct Talumno alumno_mejor_media;
    float mejor_media = 0;

    for (int i = 0; i < num_alumnos; i++) {
        if ((palumnos + i)->media > mejor_media) {
            mejor_media = (palumnos + i)->media;
            alumno_mejor_media = *(palumnos + i);
        }
    }

    printf("El alumno con mejor nota media es: %s %s con una media de %.2f",
           alumno_mejor_media.nombre, alumno_mejor_media.apellido,
           alumno_mejor_media.media);
}