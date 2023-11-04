/* Realizar un programa que solicite que se ingrese por teclado el nombre de algún archivo de texto,
trabajado hasta el momento en el práctico, para luego mostrar por pantalla el contenido del mismo, en
caso de no encontrar ese archivo mostrar un mensaje*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 300

void obtenerNombre(char nombre[]);
void buscarYControlarArchivo(char nombre[]);
void mostrarContenidoArchivo(char nombre[]);

int main(){
    char nombreArchivo[MAX];

    obtenerNombre(nombreArchivo);
    buscarYControlarArchivo(nombreArchivo);
    mostrarContenidoArchivo(nombreArchivo);

    return 0;
}

void obtenerNombre(char nombre[]){

    printf("\nIngrese el nombre del archivo a buscar: ");
    fgets(nombre, MAX, stdin);
    nombre[strcspn(nombre, "\n")] = '\0';
}

void buscarYControlarArchivo(char nombre[]){
    FILE *p;

    p = fopen(nombre, "r");
    if (p == NULL){
        printf("\nNo se encontró ningun archivo con el nombre ingresado\n");
        exit(0);
    }
    fclose(p);

}

void mostrarContenidoArchivo(char nombre[]){
    char linea[MAX];
    FILE *p;

    p = fopen(nombre, "r");

    printf("\nA continuación se mostrará el contenido del archivo:\n\n[ ");
    do {
        fgets(linea, MAX, p);
        printf("%s", linea);
    } while (feof(p) == 0);
    printf(" ]\n");

    fclose(p);
}