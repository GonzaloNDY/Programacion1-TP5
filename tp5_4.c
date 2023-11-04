/*Realizar un programa que solicite al usuario el nombre de un archivo. Se debe verificar si existe un
archivo con ese nombre, si el mismo no existe se debe crear y permitir el ingreso de caracteres. Si el
archivo existe se deben agregar caracteres al final. Luego mostrar el contenido del archivo por pantalla*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main(int argc, char *argv[]){
    char nombre[MAX], caracter;

    printf("\nIngrese el nombre del archivo que desea crear: ");
    fgets(nombre, MAX, stdin);
    nombre[strlen(nombre) - 1] = '\0';

    FILE *p;
    p = fopen(nombre, "r");
    if (p == NULL){
        printf("\nEl archivo no existe, se creará uno con el nombre que ingresó...\n");
        p = fopen(nombre, "a");
        if (p == NULL){
            printf("El archivo no se pudo crear...\n");
            exit(0);
        }
    } else {
        printf("\nEl archivo de nombre \"%s\" ya existe, no es necesario crear uno nuevo...\n", nombre);
    }
    fclose(p);

    p = fopen(nombre, "a");
    printf("\nA continuación tendra que añadir caracteres (de uno en uno) al  archivo de nombre \"%s\", para finalizar el programa presione 'F':\n", nombre);
    do {
        scanf("%c", &caracter);
        fgetc(stdin);
        if (caracter != 'F')
            fprintf(p,"%c", caracter);
    } while (caracter != 'F');
    fclose(p);

    p = fopen(nombre, "r");
    printf("\nLos caracteres guardados en el ejercicio anterior son:\n");
    do {
        caracter = fgetc(p);
        if (feof(p) == 0)
            printf("%c\n", caracter);
    } while (feof(p) == 0);

    fclose(p);

    return 0;
}