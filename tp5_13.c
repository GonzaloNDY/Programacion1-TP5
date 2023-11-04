/* Realizar un programa para gestionar el cumpleaños de UN amigo, usando una estructura que contenga
los siguientes campos: Nombre, Apellido y fecha de nacimiento. Luego almacenar los datos contenidos
en la estructura en un archivo de texto, utilizando un renglón o línea de texto con el siguiente formato:
nombre-apellido-dia-mes-anio, observar que se emplea como separador el guión. Luego presentar por
pantalla los datos de la persona registrados en el archivo*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 300

typedef struct{
    int dia, mes, anio;
} fecha;

typedef struct{
    fecha nacimiento;
    char  nombre[MAX], apellido[MAX];
} persona;

void controlApertura(char nombreArchivo[]);
void guardarDatos(char nombreArchivo[]);
void mostrarDatos(char nombreArchivo[]);

int main(){
    char nombreArchivo[] = "Cumpleaños de un amigo";
    controlApertura(nombreArchivo);
    guardarDatos(nombreArchivo);
    guardarDatos(nombreArchivo);
    return 0;
}

void controlApertura(char nombreArchivo[]){
    FILE *p;

    p = fopen(nombreArchivo, "r");
    if (p == NULL){
        printf("No se pudo abrir el archivo %s", nombreArchivo);
        exit(0);
    }
    fclose(p);
}

void guardarDatos(char nombreArchivo[]){
    FILE *p;
    persona amigo;

    p = fopen(nombreArchivo, "a");

    printf("Ingrese los datos de su amigo\n");

    printf("Nombre: ");
    fgets(amigo.nombre, MAX, stdin);
    amigo.nombre[strcspn(amigo.nombre, "\n")] = '\0';

    printf("Apellido: ");
    fgets(amigo.apellido, MAX, stdin);
    amigo.apellido[strcspn(amigo.apellido, "\n")] = '\0';

    printf("Fecha de nacimiento: ");
    
}

void mostrarDatos(char nombreArchivo[]){
    FILE *p;
    
}