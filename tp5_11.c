/* Diseñar un programa que permita leer el archivo del ejercicio 9 y cuente cuantas veces se hace
referencia a la frase: “lenguaje en C". En este caso 4 veces*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 300

void controlApertura();
int contarString();

int main(int argc, char *argv[]){

    controlApertura();
    printf("\nSe hace referencia a la frase \"lenguaje en C\" un total de %i veces\n", contarString());

    return 0;
}

void controlApertura(){
    FILE *p;

    p = fopen("lenguajeC.txt", "r");
    if (p == NULL){
        printf("\nNo se pudo abrir el archivo, se intentará nuevamente...\n");
        p = fopen("lenguajeC.txt", "r+");
        if (p == NULL){
            printf("\n\nHubo algún error durante la busqueda del archivo, el programa finalizará...\n");
            exit(0);
        }
    }
    fclose(p);

}

int contarString(){
    int contador = 0;
    char cadenaAux[MAX];
    FILE *p;
    
    p = fopen("lenguajeC.txt", "r");
    do {
        fgets(cadenaAux, MAX, p);
        if (strstr(cadenaAux, "lenguaje en C"))
            contador++;
    } while (feof(p) == 0);
    fclose(0);

    return contador;
}