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
void BuscarNombrePorPalabra(char palabraClave[], char *listasNombres[], int cantidad) {
    int encontrado = 0;
    for (int i = 0; i < cantidad; i++) {
        if (strstr(listasNombres[i], palabraClave) != NULL) {
            encontrado = 1;
            printf("El nombre '%s' contiene la palabra clave '%s'.\n", listasNombres[i], palabraClave);
        }
    }
    if (!encontrado) {
        printf("-1");
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
