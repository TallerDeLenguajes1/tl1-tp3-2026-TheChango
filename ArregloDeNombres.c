#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int NOMBRES = 50;
void mostrarNombres(char *listasNombres[], int cantidad) {
    printf("\nLos nombres ingresados son:\n");
  
    for (int i = 0; i < cantidad; i++) {
        printf("%s", listasNombres[i]);
    }
}
void BuscarNombrePorId(int id, char *listasNombres[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        if (i == id) {
            printf("Nombre encontrado: %s", listasNombres[i]);
        }else {
            printf("No se encontro el valor buscado.\n");
        }
    }
}

int main() {
    char *listasNombres[5];
    char auxiliar[NOMBRES];

    for (int i = 0; i < 5; i++) {
        printf("Ingrese el nombre %d: ", i + 1);
        fgets(auxiliar, NOMBRES, stdin);
        int numero = strlen(auxiliar);
        listasNombres[i] = (char*)malloc((numero + 1) * sizeof(char));
        strcpy(listasNombres[i], auxiliar);
    }
    mostrarNombres(listasNombres, 5);
    return 0;
}
