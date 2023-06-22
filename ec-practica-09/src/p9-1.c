#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tjugador {
    char nombre[100];
    int edad;
    int altura;
};

int jugadormasalto(struct Tjugador *pjugadores, int num_jugadores);

int jugadormasviejo(struct Tjugador *pjugadores, int num_jugadores);

void imprimirjugador(struct Tjugador jugador);

int main() {
    struct Tjugador *pjugadores;
    int num_jugadores;

    printf("Indica el número de jugadores del equipo: ");
    scanf("%d", &num_jugadores);
    while (getchar() != '\n');

    pjugadores = (struct Tjugador *) malloc(sizeof(struct Tjugador) * num_jugadores);

    for (int i = 0; i < num_jugadores; i++) {
        printf("Introduce el nombre del jugador %d: ", (i + 1));
        fgets((pjugadores + i)->nombre, 100, stdin);
        (pjugadores + i)->nombre[strcspn((pjugadores + i)->nombre, "\n")] = '\0';

        printf("Introduce la edad del jugador %d: ", (i + 1));
        scanf("%d", &(pjugadores + i)->edad);

        printf("Introduce la altura del jugador %d: ", (i + 1));
        scanf("%d", &(pjugadores + i)->altura);
        while (getchar() != '\n');
        printf("\n");
    }

    int index_alto = jugadormasalto(pjugadores, num_jugadores);
    int index_viejo = jugadormasviejo(pjugadores, num_jugadores);

    printf("Jugador más alto:\n");
    imprimirjugador(*(pjugadores + index_alto));

    printf("\n");

    printf("Jugador más viejo:\n");
    imprimirjugador(*(pjugadores + index_viejo));

    free(pjugadores);
    return 0;
}

int jugadormasalto(struct Tjugador *pjugadores, int num_jugadores) {
    int index = 0;
    int altura_max = 0;

    for (int i = 0; i < num_jugadores; i++) {
        if ((pjugadores + i)->altura > altura_max) {
            altura_max = (pjugadores + i)->altura;
            index = i;
        }
    }

    return index;
}

int jugadormasviejo(struct Tjugador *pjugadores, int num_jugadores) {
    int index = 0;
    int edad_max = 0;

    for (int i = 0; i < num_jugadores; i++) {
        if ((pjugadores + i)->edad > edad_max) {
            edad_max = (pjugadores + i)->edad;
            index = i;
        }
    }

    return index;
}

void imprimirjugador(struct Tjugador jugador) {
    printf("\nNombre: %s\nEdad: %d\nAltura: %d\n", jugador.nombre, jugador.edad, jugador.altura);
}