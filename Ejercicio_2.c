#include <stdio.h>
void despliegaAhorcado(char* nombreArchivoFigura);
int main(){
despliegaAhorcado("figura_5.txt");
  return 0;
}
void despliegaAhorcado(char* nombreArchivoFigura) {
    FILE* archivo = fopen(nombreArchivoFigura, "r");
    if (archivo == NULL) {
        printf("No se puede abrir el archivo %s\n", nombreArchivoFigura);
        return;
    }
    char linea[100];
    while (fgets(linea, sizeof(linea), archivo)) {
        printf("%s", linea);
    }
    fclose(archivo);
}
