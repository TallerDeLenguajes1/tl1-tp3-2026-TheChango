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
void BuscarNombrePorId(int id, char *listasNombres[], int cantidad) {
    int encontrado2 = 0;
    for (int i = 0; i < cantidad; i++) {
        if (i == id) {
            printf("Nombre encontrado: %s", listasNombres[i]);
            encontrado2 = 1;
        }
    }
    if (!encontrado2) {
        printf("id no encontrado.\n");
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

    int opcion;
    printf("Bienvenido al programa de busqueda de nombres.\n");
    printf("Seleccione una opcion:\n");
    printf("1. Buscar nombre por palabra clave.\n");
    printf("2. Buscar nombre por ID.\n");
    scanf("%d", &opcion);

    if (opcion == 1) {
        char palabraClave[NOMBRES];
        printf("Ingrese la palabra clave a buscar: ");
        scanf("%s", palabraClave);
        BuscarNombrePorPalabra(palabraClave, listasNombres, 5);
    } else if (opcion == 2) {
        int id;
        printf("Ingrese el ID del nombre a buscar (0-4): ");
        scanf("%d", &id);
        BuscarNombrePorId(id, listasNombres, 5);
    } else {
        printf("Opcion invalida.\n");
    }


    return 0;
}
