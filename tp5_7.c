/* Realizar un programa que solicite al usuario el nombre de un archivo, almacene caracteres en el mismo y
luego lo presente por pantalla. Al ingresar el nombre del archivo se debe verificar si existe, si el mismo
no existe se debe crear y permitir el ingreso de caracteres. Si el archivo existe se deben agregar
caracteres al final. Luego mostrar el contenido del archivo por pantalla. Usar:
○ Una función para verificar la existencia, en caso de no existir, realizar la creación del archivo.
○ Una función para solicitar al usuario los caracteres y almacenarlos en el archivo.
○ Una función para mostrar el contenido del archivo */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void controlApertura(char nombre[]);
void escritura(char nombre[]);
void lectura(char nombre[]);

int main(int argc, char *argv[]){
    char nombre[MAX];

    printf("\nIngrese el nombre del archivo que desea crear: ");
    fgets(nombre, MAX, stdin);
    nombre[strcspn(nombre, "\n")] = '\0';

    controlApertura(nombre);
    escritura(nombre);
    lectura(nombre);

    return 0;
}

void controlApertura(char nombre[]){
    FILE *p;
    p = fopen(nombre, "r");
    if (p == NULL){
        printf("\nEl archivo no existe, se creará uno nuevo...\n");
        p = fopen(nombre, "w");
        if (p == NULL){
            printf("\nEl archivo no pudo ser creado, el programa finalizará...\n");
            exit(0);
        }
    } else {
        printf("\nEl archivo ya existe, no es necesario crearlo\n");
    }
    fclose(p);
}

void escritura(char nombre[]){
    char caracter;
    FILE *p;

    p = fopen(nombre, "a");
    printf("\nIngrese caracteres de uno en uno, para finalizar el programa presione 'F':\n");
    do {
        scanf("%c", &caracter);
        fgetc(stdin);
        if (caracter != 'F'){
            fprintf(p,"%c", caracter);
        }
    } while (caracter != 'F');
    
    fclose(p);
}

void lectura(char nombre[]){
    char caracter;
    FILE *p;

    p = fopen(nombre, "r");
    printf("\nLos caracteres ingresados en el archivo anterior son:\n");
    do {
        caracter = fgetc(p);
        if (feof(p) == 0)
            printf("%c\n", caracter);
    } while (feof(p) == 0);
    
    fclose(p);
}