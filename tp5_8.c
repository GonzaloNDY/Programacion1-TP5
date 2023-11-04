/*Realizar un programa que permita ingresar cadenas de cadenaes que contengan dos o más palabras en
un archivo llamado cadenas.txt., almacenar un renglón o línea de texto por cada cadena ingresada. El
ingreso de cadenas finaliza con la cadena: "Fin del ingreso". Consideraciones:
○ El control de que las cadenas ingresadas tengan dos o más palabras debe realizarse con una función.
○ La cadena “Fin del ingreso” no debe ser escrita en el archivo */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void controlApertura(char nombre[]);
void escritura(char nombre[]);
void lectura(char nombre[]);

int main(int argc, char *argv[]){
    char nombre[] = "cadenas.txt";
    
    controlApertura(nombre);
    escritura(nombre);
    lectura(nombre);

    return 0;
}

void controlApertura(char nombre[]){
    FILE *p;
    p = fopen(nombre, "r");
    if (p == NULL){
        printf("\nEl archivo no existe ,se creará uno nuevo...\n");
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
    char cadena[MAX];
    FILE *p;

    p = fopen(nombre, "a");
    printf("\nIngrese cadenas de 2 o más palabras, para finalizar el programa escriba \"Fin del ingreso\":\n\n");
    do {
        fgets(cadena, MAX, stdin);
        cadena[strlen(cadena) - 1] = '\0';
        if ((strchr(cadena, ' ') != 0) && cadena[0] != ' ' && strcmp(cadena, "Fin del ingreso") != 0){
            fprintf(p,"%s\n", cadena);
        } else {
            printf("La cadena \"%s\" tiene menos de 2 palabras, no se guardará en el archivo\n", cadena);
        }
    } while (strcmp(cadena, "Fin del ingreso") != 0);
    
    fclose(p);
}

void lectura(char nombre[]){
    char cadena[MAX];
    FILE *p;

    p = fopen(nombre, "r");

    printf("\nLas cadenas ingresadas en el archivo anterior son:\n\n");
    do {
        fgets(cadena, MAX, p);
        if (feof(p) == 0)
            printf("%s", cadena);
    } while (feof(p) == 0);

    fclose(p);
}