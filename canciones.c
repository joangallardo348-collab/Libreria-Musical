#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "canciones.h"


const char *clasificaciones[] = {
    "Pasillos", "Rancheras", "Cumbia", "Baladas", "Pop", "Rock", "Jazz", "Salsa", "Clasica","Electronica"
};

void inicializarCanciones(Cancion canciones[], int *cantidad) {
    *cantidad = 0;
}

int validarCodigo(Cancion canciones[], int cantidad, const char *codigo)
{
    int i;

    if(strlen(codigo) == 0 || strlen(codigo) > 15) 
        return 0;

    for(i = 0; codigo[i] != '\0'; i++)
    {
        if(isspace((unsigned char)codigo[i]))
            return 0;

        if(!isalnum((unsigned char)codigo[i]))
            return 0;
    }

    for(i = 0; i < cantidad; i++)
    {
        #ifdef _WIN32
            if(_stricmp(canciones[i].codigo, codigo) == 0)
        #else
            if(strcasecmp(canciones[i].codigo, codigo) == 0)
        #endif
            return 0;
    }

    return 1;
}

