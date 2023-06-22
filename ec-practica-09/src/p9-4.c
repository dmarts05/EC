#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Tpunto {
    float x;
    float y;
    float z;
};

struct Ttriangulo {
    struct Tpunto punto1;
    struct Tpunto punto2;
    struct Tpunto punto3;
    float lado1;
    float lado2;
    float lado3;
    float perimetro;
    float area;
};

int argumentos_validos(FILE *pfile);

int calcular_numero_triangulos(FILE *pfile);

void insertar_datos_puntos(FILE *pfile, struct Tpunto *puntos, int num_triangulos);

void insertar_puntos_en_triangulos(struct Tpunto *puntos, struct Ttriangulo *ptriangulos, int num_triangulos);

void calcular_lados_triangulos(struct Ttriangulo *ptriangulos, int num_triangulos);

void calcular_perimetro_triangulos(struct Ttriangulo *ptriangulos, int num_triangulos);

void calcular_area_triangulos(struct Ttriangulo *ptriangulos, int num_triangulos);

void calcular_mayor_perimetro(struct Ttriangulo *ptriangulos, int num_triangulos);

void calcular_mayor_area(struct Ttriangulo *ptriangulos, int num_triangulos);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Error, el número de argumentos no es válido");
        exit(EXIT_FAILURE);
    }

    FILE *pfile;
    struct Tpunto *puntos;
    struct Ttriangulo *ptriangulos;
    int num_triangulos;
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

    num_triangulos = calcular_numero_triangulos(pfile);

    rewind(pfile);

    ptriangulos =
            (struct Ttriangulo *) malloc(sizeof(struct Ttriangulo) * num_triangulos);

    puntos = (struct Tpunto *) malloc(sizeof(struct Tpunto) * 3 * num_triangulos);

    insertar_datos_puntos(pfile, puntos, num_triangulos);
    pclose(pfile);

    insertar_puntos_en_triangulos(puntos, ptriangulos, num_triangulos);

    calcular_lados_triangulos(ptriangulos, num_triangulos);
    calcular_perimetro_triangulos(ptriangulos, num_triangulos);
    calcular_area_triangulos(ptriangulos, num_triangulos);

    calcular_mayor_perimetro(ptriangulos, num_triangulos);
    calcular_mayor_area(ptriangulos, num_triangulos);

    free(puntos);
    free(ptriangulos);
    return 0;
}

int argumentos_validos(FILE *pfile) {
    char *line = NULL;
    size_t line_size = 0;
    int arg_correcto = 3;
    int result = 1;

    while ((getline(&line, &line_size, pfile) != -1)) {
        int counter = 0;

        char line_str[100];
        strcpy(line_str, line);
        char *tokens = strtok(line_str, ";");

        while (tokens != NULL) {
            tokens = strtok(NULL, ";");
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

int calcular_numero_triangulos(FILE *pfile) {
    char *line = NULL;
    size_t line_size = 0;
    int num_triangulos = 0;

    while ((getline(&line, &line_size, pfile) != -1)) {
        num_triangulos++;
    }

    free(line);
    return num_triangulos;
}

void insertar_datos_puntos(FILE *pfile, struct Tpunto *puntos, int num_triangulos) {
    float x;
    float y;
    float z;
    int counter = 0;

    while (fscanf(pfile, "%f %f %f;", &x, &y, &z) != 0 && counter < (num_triangulos * 3)) {
        (puntos + counter)->x = x;
        (puntos + counter)->y = y;
        (puntos + counter)->z = z;
        counter++;
    }
}

void insertar_puntos_en_triangulos(struct Tpunto *puntos, struct Ttriangulo *ptriangulos, int num_triangulos) {
    int counter = 0;
    for (int i = 0; i < num_triangulos; i++) {
        (ptriangulos + i)->punto1 = *(puntos + counter++);
        (ptriangulos + i)->punto2 = *(puntos + counter++);
        (ptriangulos + i)->punto3 = *(puntos + counter++);
    }
}

void calcular_lados_triangulos(struct Ttriangulo *ptriangulos, int num_triangulos) {
    for (int i = 0; i < num_triangulos; i++) {
        (ptriangulos + i)->lado1 = sqrtf(powf((ptriangulos + i)->punto2.x - (ptriangulos + i)->punto1.x, 2) +
                                         powf((ptriangulos + i)->punto2.y - (ptriangulos + i)->punto1.y, 2) +
                                         powf((ptriangulos + i)->punto2.z - (ptriangulos + i)->punto1.z, 2));
        (ptriangulos + i)->lado2 = sqrtf(powf((ptriangulos + i)->punto3.x - (ptriangulos + i)->punto2.x, 2) +
                                         powf((ptriangulos + i)->punto3.y - (ptriangulos + i)->punto2.y, 2) +
                                         powf((ptriangulos + i)->punto3.z - (ptriangulos + i)->punto2.z, 2));
        (ptriangulos + i)->lado3 = sqrtf(powf((ptriangulos + i)->punto3.x - (ptriangulos + i)->punto1.x, 2) +
                                         powf((ptriangulos + i)->punto3.y - (ptriangulos + i)->punto1.y, 2) +
                                         powf((ptriangulos + i)->punto3.z - (ptriangulos + i)->punto1.z, 2));
    }
}

void calcular_perimetro_triangulos(struct Ttriangulo *ptriangulos, int num_triangulos) {
    for (int i = 0; i < num_triangulos; i++) {
        (ptriangulos + i)->perimetro = (ptriangulos + i)->lado1 + (ptriangulos + i)->lado2 + (ptriangulos + i)->lado3;
    }
}

void calcular_area_triangulos(struct Ttriangulo *ptriangulos, int num_triangulos) {
    for (int i = 0; i < num_triangulos; i++) {
        float sp = (ptriangulos + i)->perimetro * 0.5;
        (ptriangulos + i)->area = sqrtf(sp * (sp - (ptriangulos + i)->lado1) * (sp - (ptriangulos + i)->lado2) *
                                        (sp - (ptriangulos + i)->lado3));
    }
}

void calcular_mayor_perimetro(struct Ttriangulo *ptriangulos, int num_triangulos) {
    float perimetro_max = 0;
    struct Ttriangulo triangulo_perimetro;

    for (int i = 0; i < num_triangulos; i++) {
        if ((ptriangulos + i)->perimetro > perimetro_max) {
            perimetro_max = (ptriangulos + i)->perimetro;
            triangulo_perimetro = *(ptriangulos + i);
        }
    }

    printf("Puntos del triángulo con mayor perímetro:\n(%.2f, %.2f, %.2f) (%.2f, %.2f, %.2f) (%.2f, %.2f, %.2f)\n",
           triangulo_perimetro.punto1.x, triangulo_perimetro.punto1.y, triangulo_perimetro.punto1.z,
           triangulo_perimetro.punto2.x, triangulo_perimetro.punto2.y, triangulo_perimetro.punto2.z,
           triangulo_perimetro.punto3.x, triangulo_perimetro.punto3.y, triangulo_perimetro.punto3.z);
}

void calcular_mayor_area(struct Ttriangulo *ptriangulos, int num_triangulos) {
    float area_max = 0;
    struct Ttriangulo triangulo_area;

    for (int i = 0; i < num_triangulos; i++) {
        if ((ptriangulos + i)->area > area_max) {
            area_max = (ptriangulos + i)->area;
            triangulo_area = *(ptriangulos + i);
        }
    }

    printf("Puntos del triángulo con mayor área:\n(%.2f, %.2f, %.2f) (%.2f, %.2f, %.2f) (%.2f, %.2f, %.2f)\n",
           triangulo_area.punto1.x, triangulo_area.punto1.y, triangulo_area.punto1.z,
           triangulo_area.punto2.x, triangulo_area.punto2.y, triangulo_area.punto2.z,
           triangulo_area.punto3.x, triangulo_area.punto3.y, triangulo_area.punto3.z);
}