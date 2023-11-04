/*Realizar un programa que permita mostrar por pantalla el contenido del archivoTexto.txt*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void controlApertura(char nombre[]);
void lectura(char nombre[]);

int main(int argc, char *argv[]){
    char nombre[] = "ejercicio.txt";

    controlApertura(nombre);
    lectura(nombre);

    return 0;
}

void controlApertura(char nombre[]){
    FILE *p;
    p = fopen(nombre, "r");
    if (p == NULL){
        printf("El archivo no se pudo encontrar, el programa finalizará...\n");
        exit(0);
    }
    fclose(p);
}

void lectura(char nombre[]){
    char caracter;

    FILE *p;
    p = fopen(nombre, "r");
    printf("\nLos caracteres ingresados en el archivo anterior son:\n");
    do {
        caracter = fgetc(p);
        printf("%c\n", caracter);
    } while (feof(p) == 0);
    
    fclose(p);
}