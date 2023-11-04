/*Realizar un programa que permita ingresar caracteres desde el teclado, el programa deberá escribir los
caracteres a medida que se ingresen en un archivo de texto llamado archivoTexto.txt El ingreso de
caracteres debe finalizar cuando se ingrese la letra F, esta última no deberá ser escrita en el archivo*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void controlApertura(char nombre[]);
void escritura(char nombre[]);

int main(int argc, char *argv[]){
    char nombre[] = "ejercicio.txt";

    controlApertura(nombre);
    escritura(nombre);

    return 0;
}

void controlApertura(char nombre[]){
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