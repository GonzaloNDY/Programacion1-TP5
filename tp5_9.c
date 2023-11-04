/*Dado el siguiente fragmento:
[ Suele decirse que programar en lenguaje en C es muy difícil!!! y las grandes masas no comprenden
por qué, ya que sienten que al leer en un fin de semana un Manual sobre lenguaje en C,
comprenderlo y aplicar exitosamente los Ejemplos del Texto han dominado el lenguaje. Y es allí el
gran error, el lenguaje en C es mucho más que su propio contenido. Yo solía decir, años atrás en que
impartí varios Cursos de lenguaje en C, que el citado lenguaje no era complejo, por el contrario, es
estupendamente sencillo y explícito, que su auténtico valor radica en su amplio alcance y versátil
profundidad. ]
Utilizando un editor de texto, almacenar el fragmento en un archivo de texto llamado lenguajeC.txt en el
directorio de trabajo. Implementar un programa que muestre el contenido de este archivo por pantalla*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 500

void controlApertura();
void mostrarTexto();

int main( int argc, char *argv[]){
    controlApertura();
    mostrarTexto();
    return 0;
}

void controlApertura(){
    FILE *p;
    p = fopen("lenguajeC.txt", "r");
    if (p == NULL){
        printf("\nEl archivo no pudo ser abierto, se intentará nuevamente...\n\n");
        p = fopen("lenguajeC.txt", "r+");
        if (p = NULL){
            printf("\nOcurrió algún error inesperado durante la ejecución, finalizando el programa\n\n");
            exit(0);
        }
    }
    fclose(p);
}

void mostrarTexto(){
    char cadena[MAX];
    FILE *p;
    
    printf("\n");

    p = fopen("lenguajeC.txt", "r");
    do {
        fgets(cadena, MAX, p);
        if (feof(p) == 0)
            printf("%s", cadena);
    } while (feof(p) == 0);
    fclose(p);

    printf("\n");
}