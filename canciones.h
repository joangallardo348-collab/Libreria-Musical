#ifndef CANCIONES_H
#define CANCIONES_H

#define MAX_CANCIONES 1000
#define MAX_CLASIFICACIONES 10
#define MAX_CODIGO 15
#define MAX_TITULO 100
#define MAX_NOMBRE 100
#define MAX_CLASIF 30

typedef struct {
    char codigo[MAX_CODIGO];
    char titulo[MAX_TITULO];
    char clasificacion[MAX_CLASIF];
    char compositor[MAX_NOMBRE];
    char artista[MAX_NOMBRE];
    int duracion; // en segundos
} Cancion;



#endif
