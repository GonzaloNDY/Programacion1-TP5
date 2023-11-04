/* Diseñar un programa que permita leer el archivo del ejercicio 9, solicite un caracter al usuario y cuente
cuántas veces se encuentra el caracter en el archivo. Presente el resultado por pantalla*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char obtenerCaracter();
void controlApertura();
int contarCaracter(char caracter);

int main(int argc, char *argv[]){
    char caracter;
    
    controlApertura();
    caracter = obtenerCaracter();
    printf("\nEl caracter '%c' se encuentra %i veces en el texto de nombre \"lenguajeC.txt\"\n", caracter, contarCaracter(caracter));

    return 0;
}

char obtenerCaracter(){
    char cadena[MAX];

    printf("\nIngrese una letra: ");
    do {
        fgets(cadena, MAX, stdin);
        if (strlen(cadena) > 2 || !isalpha(cadena[0]))
            printf("Tiene que ingresar un único caracter alfabetico, intente nuevamente: ");
    } while (strlen(cadena) > 2 || !isalpha(cadena[0]));

    return cadena[0];
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

int contarCaracter(char caracter){
    int contador = 0;
    char caracterAux;
    FILE *p;

    p = fopen("lenguajeC.txt", "r");
    do {
        caracterAux = fgetc(p);
        if (caracterAux == caracter)
            contador++;
    } while (feof(p) == 0);
    fclose(p);
    
    return contador;
}