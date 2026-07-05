#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "archivos.h"
#include "canciones.h"

#define ARCHIVO "canciones.csv"

void cargarArchivo(Cancion canciones[], int *cantidad) {
    FILE *archivo;
    char linea[500];
    char *token;
    int i;
    
    archivo = fopen(ARCHIVO, "r");
    if (archivo == NULL) {
        printf("\nArchivo no encontrado. Se crear uno nuevo al guardar.\n");
        *cantidad = 0;
        return;
    }
    
    // Leer y descartar la cabecera
    fgets(linea, sizeof(linea), archivo);
    
    *cantidad = 0;
    while (fgets(linea, sizeof(linea), archivo) != NULL && *cantidad < MAX_CANCIONES) {
        // Eliminar el salto de linea
        linea[strcspn(linea, "\n")] = 0;
        
        // Parsear CSV
        token = strtok(linea, ";");
        if (token == NULL) continue;
        strcpy(canciones[*cantidad].codigo, token);
        
        token = strtok(NULL, ";");
        if (token == NULL) continue;
        strcpy(canciones[*cantidad].titulo, token);
        
        token = strtok(NULL, ";");
        if (token == NULL) continue;
        strcpy(canciones[*cantidad].clasificacion, token);
        
        token = strtok(NULL, ";");
        if (token == NULL) continue;
        strcpy(canciones[*cantidad].compositor, token);
        
        token = strtok(NULL, ";");
        if (token == NULL) continue;
        strcpy(canciones[*cantidad].artista, token);
        
        token = strtok(NULL, ";");
        if (token == NULL) continue;
        canciones[*cantidad].duracion = atoi(token);
        
        (*cantidad)++;
    }
    
    fclose(archivo);
    printf("\nSe cargaron %d canciones del archivo.\n", *cantidad);
}
void guardarArchivo(Cancion canciones[], int cantidad) {
    FILE *archivo;
    int i;
    
    archivo = fopen(ARCHIVO, "w");
    if (archivo == NULL) {
        printf("\nError al abrir el archivo para guardar.\n");
        return;
    }
    
    // Escribir cabecera
    fprintf(archivo, "codigo_cancion;titulo;clasificacion;compositor;artista;duracion_segundos\n");
    
    // Escribir datos
    for (i = 0; i < cantidad; i++) {
        fprintf(archivo, "%s;%s;%s;%s;%s;%d\n",
                canciones[i].codigo,
                canciones[i].titulo,
                canciones[i].clasificacion,
                canciones[i].compositor,
                canciones[i].artista,
                canciones[i].duracion);
    }
    
    fclose(archivo);
    printf("\nSe guardaron %d canciones en el archivo.\n", cantidad);
}