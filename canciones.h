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

// Declaracion de funciones
void inicializarCanciones(Cancion canciones[], int *cantidad);

void registrarCancion(Cancion canciones[], int *cantidad);
void listarCanciones(Cancion canciones[], int cantidad);
void buscarCancion(Cancion canciones[], int cantidad);
void actualizarCancion(Cancion canciones[], int cantidad);
void eliminarCancion(Cancion canciones[], int *cantidad);

int validarCodigo(Cancion canciones[], int cantidad, const char *codigo);
int buscarPorCodigo(Cancion canciones[], int cantidad, const char *codigo);

void mostrarCancion(Cancion cancion);
void formatearDuracion(int segundos, char *buffer);

int str_igual_ignore_case(const char *s1, const char *s2);
char *str_buscar_ignore_case(const char *pajar, const char *aguja);


#endif
