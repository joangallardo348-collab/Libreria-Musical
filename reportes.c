#include <stdio.h>
#include <string.h>
#include "reportes.h"
#include "canciones.h"

extern const char *clasificaciones[];

void mostrarDuracion(Cancion canciones[], int cantidad) {
    if (cantidad == 0) {
        printf("\nNo hay canciones registradas.\n");
        return;
    }
    
    char codigo[MAX_CODIGO];
    printf("\n==============================\n");
    printf("DURACION DE CANCION\n");
    printf("==============================\n");
    printf("Ingrese el codigo de la cancion: ");
    scanf("%15s", codigo);
    
    int index = -1;
    for (int i = 0; i < cantidad; i++) {
        if (strcmp(canciones[i].codigo, codigo) == 0) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("\nCancion no encontrada.\n");
        return;
    }
    
    char duracion_str[20];
    formatearDuracion(canciones[index].duracion, duracion_str);
    printf("\nDuracion de '%s': %s (%d segundos)\n", 
           canciones[index].titulo, duracion_str, canciones[index].duracion);
}

void tiempoTotal(Cancion canciones[], int cantidad) {
    if (cantidad == 0) {
        printf("\nNo hay canciones registradas.\n");
        return;
    }
    
    int total_segundos = 0;
    for (int i = 0; i < cantidad; i++) {
        total_segundos += canciones[i].duracion;
    }
    
    char duracion_str[20];
    formatearDuracion(total_segundos, duracion_str);
    printf("\nTiempo total de reproduccion: %s\n", duracion_str);
}

void cancionMasLarga(Cancion canciones[], int cantidad) {
    if (cantidad == 0) {
        printf("\nNo hay canciones registradas.\n");
        return;
    }
    
    int max_index = 0;
    for (int i = 1; i < cantidad; i++) {
        if (canciones[i].duracion > canciones[max_index].duracion) {
            max_index = i;
        }
    }
    
    printf("\nCancion mas larga:\n");
    mostrarCancion(canciones[max_index]);
}

void cancionMasCorta(Cancion canciones[], int cantidad) {
    if (cantidad == 0) {
        printf("\nNo hay canciones registradas.\n");
        return;
    }
    
    int min_index = 0;
    for (int i = 1; i < cantidad; i++) {
        if (canciones[i].duracion < canciones[min_index].duracion) {
            min_index = i;
        }
    }
    
    printf("\nCancion mas corta:\n");
    mostrarCancion(canciones[min_index]);
}

void cantidadPorClasificacion(Cancion canciones[], int cantidad) {

    if (cantidad == 0) {
        printf("\nNo hay canciones registradas.\n");
        return;
    }

    int conteos[MAX_CLASIFICACIONES] = {0};

    for (int i = 0; i < cantidad; i++) {
        for (int j = 0; j < MAX_CLASIFICACIONES; j++) {
            if (strcmp(canciones[i].clasificacion, clasificaciones[j]) == 0) {
                conteos[j]++;
                break;
            }
        }
    }

    printf("\n==============================\n");
    printf("CANCIONES POR CLASIFICACION\n");
    printf("==============================\n");

    for (int i = 0; i < MAX_CLASIFICACIONES; i++) {
        if (conteos[i] > 0) {
            printf("%-15s: %d cancion(es)\n", clasificaciones[i], conteos[i]);
        }
    }
}

void promedioDuracion(Cancion canciones[], int cantidad) {
    if (cantidad == 0) {
        printf("\nNo hay canciones registradas.\n");
        return;
    }
    
    int total_segundos = 0;
    for (int i = 0; i < cantidad; i++) {
        total_segundos += canciones[i].duracion;
    }
    
    double promedio = (double)total_segundos / cantidad;
    char duracion_str[20];
    formatearDuracion((int)promedio, duracion_str);
    
    printf("\nDuracion promedio: %.2f segundos (%s)\n", promedio, duracion_str);
}