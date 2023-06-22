#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct Tpunto {
    float x;
    float y;
};

struct Ttriangulo {
    struct Tpunto *puntos;
    float perimetro;
    float area;
};

float *calcular_lados(struct Tpunto *puntos);

float calcular_perimetro(float *lados);

float calcular_area(float *lados, float perimetro);

int main() {
    struct Tpunto *puntos;
    struct Ttriangulo triangulo;
    float *lados;
    float perimetro;
    float area;

    puntos = (struct Tpunto *) malloc(sizeof(struct Tpunto) * 3);

    for (int i = 0; i < 3; i++) {
        printf("Introduce la coordenada X del punto %d: ", (i + 1));
        scanf("%f", &(puntos + i)->x);

        printf("Introduce la coordenada Y del punto %d: ", (i + 1));
        scanf("%f", &(puntos + i)->y);
        printf("\n");
    }

    lados = calcular_lados(puntos);
    perimetro = calcular_perimetro(lados);
    area = calcular_area(lados, perimetro);

    triangulo.puntos = puntos;
    triangulo.perimetro = perimetro;
    triangulo.area = area;

    printf("Puntos:\n");
    for (int i = 0; i < 3; i++) {
        printf("(%.2f; %.2f)\n", (triangulo.puntos + i)->x, (triangulo.puntos + i)->y);
    }

    printf("Perímetro:\n%.2f\n", triangulo.perimetro);
    printf("Área:\n%.2f", triangulo.area);

    free(lados);
    free(puntos);
    return 0;
}

float *calcular_lados(struct Tpunto *puntos) {
    float *lados;
    lados = (float *) malloc(sizeof(float) * 3);

    *(lados) = sqrtf(powf((puntos + 1)->x - (puntos)->x, 2) +
                     powf((puntos + 1)->y - (puntos)->y, 2));

    *(lados + 1) = sqrtf(powf((puntos + 2)->x - (puntos + 1)->x, 2) +
                         powf((puntos + 2)->y - (puntos + 1)->y, 2));

    *(lados + 2) = sqrtf(powf((puntos + 2)->x - (puntos)->x, 2) +
                         powf((puntos + 2)->y - (puntos)->y, 2));

    return lados;
}

float calcular_perimetro(float *lados) {
    float perimetro = 0;

    for (int i = 0; i < 3; i++) {
        perimetro += *(lados + i);
    }

    return perimetro;
}

float calcular_area(float *lados, float perimetro) {
    float sp = 0.5 * perimetro;
    return sqrtf(sp * (sp - *lados) * (sp - *(lados + 1)) * (sp - *(lados + 2)));
}