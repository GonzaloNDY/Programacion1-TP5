/*Realizar un programa que permita crear un archivo que tenga el nombre ejercicio1.txt, luego ingresar
por teclado una cadena de caracteres y escribirla en el archivo, finalmente cerrar el archivo*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main(int argc, char *argv[]){
    char nombre[] = "ejercicio.txt", cadena[MAX];

    FILE *p;
    p = fopen(nombre, "w");
    if (p == NULL){
        printf("El archivo no se pudo crear, se intentará nuevamente\n");
        p = fopen(nombre, "w+");
        if (p == NULL){
            printf("El archivo no se pudo crear...\n");
            exit(0);
        }
    }

    printf("\nIngrese una cadena de caracteres: ");
    fgets(cadena, MAX, stdin);
    cadena[strlen(cadena) - 1] = '\0';
    fprintf(p,"%s\n", cadena);
    fclose(p);

    return 0;
}