/*Realizar un programa que permita abrir y mostrar por pantalla el contenido del archivo ejercicio1.txt*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main(int argc, char *argv[]){
    char nombre[] = "ejercicio.txt", cadena[MAX];

    FILE *p;
    p = fopen(nombre, "r");
    if (p == NULL){
        printf("El archivo no existe...\n");
        exit(0);
    }
    
    fgets(cadena, MAX, p);
    printf("\nLa cadena guardada en el ejercicio anterior es: %s\n", cadena);
    fclose(p);

    return 0;
}