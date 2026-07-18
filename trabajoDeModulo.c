#include <stdio.h>
#include <stdlib.h>

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

struct Producto {
 int ProductoID; //Numerado en ciclo iterativo
 int Cantidad; // entre 1 y 10
 char *TipoProducto; // Algún valor del arreglo TiposProductos
 float PrecioUnitario; // entre 10 - 100
};

struct Cliente {
int ClienteID; // Numerado en el ciclo iterativo
char *NombreCliente; // Ingresado por usuario
int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
struct Producto *Productos; //El tamaño de este arreglo depende de la variable
 // “CantidadProductosAPedir”
};

int costoTotal(struct Cliente cliente) {
    int total = 0;
    for(int i = 0; i < cliente.CantidadProductosAPedir; i++) {
        total += cliente.Productos[i].Cantidad * cliente.Productos[i].PrecioUnitario;
    }
    return total;
}

int main() {
    int cantidadClientes;
    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &cantidadClientes);

    struct Cliente *clientes = malloc(cantidadClientes * sizeof(struct Cliente));
    for(int i = 0; i < cantidadClientes; i++) {
        clientes[i].ClienteID = i + 1;
        printf("Ingrese el nombre del cliente %d:  ", clientes[i].ClienteID);
        scanf("%s", clientes[i].NombreCliente);
        clientes[i].CantidadProductosAPedir = rand() % 5 + 1;
        clientes[i].Productos = malloc(clientes[i].CantidadProductosAPedir * sizeof(struct Producto));
        for(int j = 0; j < clientes[i].CantidadProductosAPedir; j++) {
            clientes[i].Productos[j].ProductoID = j + 1;
            clientes[i].Productos[j].Cantidad = rand() % 10 + 1;
            clientes[i].Productos[j].TipoProducto = TiposProductos[rand() % 5];
            clientes[i].Productos[j].PrecioUnitario = rand() % 100 + 10;
        }
    }

    for(int i = 0; i < cantidadClientes; i++) {
        printf("Cliente %d: %s\n", clientes[i].ClienteID, clientes[i].NombreCliente);
        printf("cantidad de productos a pedir: %d\n", clientes[i].CantidadProductosAPedir);
        for(int j = 0; j < clientes[i].CantidadProductosAPedir; j++) {
            printf("producto %d: %s, cantidad: %d, precio unitario: %.2f\n", 
                clientes[i].Productos[j].ProductoID, 
                clientes[i].Productos[j].TipoProducto, 
                clientes[i].Productos[j].Cantidad, 
                clientes[i].Productos[j].PrecioUnitario);
        }
        printf("Costo total: %.2f\n", costoTotal(clientes[i]));
    }


    return 0;
}
