#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LONGITUD 100
#define MAX_CANTIDAD 100


int palabra(char palabras[MAX_CANTIDAD][MAX_LONGITUD],char*archivos);
int leerPalabrasDeArchivo(char*nombreArchivo,char*arreglo);

int main() {
    char nombreArchivo[] = "animales.txt";
    char arreglo[MAX_LONGITUD * MAX_CANTIDAD] = {0};
    int num_palabras = leerPalabrasDeArchivo(nombreArchivo, arreglo);
    printf("Se leyeron %d palabras del archivo:\n%s\n", num_palabras, arreglo);
    return 0;
}

int palabra(char palabras[MAX_CANTIDAD][MAX_LONGITUD], char* archivos) {
    FILE* fp = fopen(archivos, "r");
    int count = 0;
    if (fp == NULL){
        printf("No se pudo abrir el archivo %s\n",archivos);
        exit(1);
    }
    while (fscanf(fp, "%s",palabras[count]) == 1) {
        count++;
        if (count == MAX_CANTIDAD) {
            printf("El archivo %s contiene demasiadas palabras.\n",archivos);
            exit(1);
        }
    }
    fclose(fp);
    return count;
}

int leerPalabrasDeArchivo(char *nombreArchivo, char *arreglo) {
    char palabras[MAX_CANTIDAD][MAX_LONGITUD];
    int num_palabras =palabra(palabras, nombreArchivo);
    int longitud_arreglo = 0;
    
    for (int i = 0; i < num_palabras; i++) {
        int longitud_palabra = strlen(palabras[i]);
        if (longitud_arreglo+longitud_palabra+1>MAX_LONGITUD * MAX_CANTIDAD) {
            printf("El arreglo es demasiado pequeño para almacenar todas las palabras del archivo.\n");
            exit(1);
        }
        strcpy(arreglo + longitud_arreglo,palabras[i]);
        longitud_arreglo += longitud_palabra + 1;
        arreglo[longitud_arreglo-1] = ' ';
    }
    arreglo[longitud_arreglo-1] ='\0';
    return num_palabras;
}
