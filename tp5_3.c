/*Realizar un programa que permita ingresar caracteres desde el teclado, el programa deberá escribir los
caracteres a medida que se ingresen en un archivo de texto llamado archivoTexto.txt El ingreso de
caracteres debe finalizar cuando se ingrese la letra F, esta última no deberá ser escrita en el archivo.
Luego debe presentar por pantalla el contenido del archivo cargado*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main(int argc, char *argv[]){
    char caracter, nombre[MAX] = "archivoTexto.txt";

    FILE *p;
    p = fopen(nombre, "w");

    if (p == NULL){
        printf("\nEl archivo no se pudo crear, se intentará nuevamente\n");
        p = fopen(nombre, "w+");
        if (p == NULL){
            printf("\nEl archivo no se pudo crear...\n");
            exit(0);
        }
    }

    printf("\nIngrese caracteres (de uno en uno), para finalizar el programa presione 'F':\n");
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