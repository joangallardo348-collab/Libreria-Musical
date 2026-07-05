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

void convertirMayusculas(char texto[])
	{
		int i;

		for(i = 0; texto[i] != '\0'; i++)
		{
			texto[i] = toupper((unsigned char)texto[i]);
		}
	}

int buscarPorCodigo(Cancion canciones[], int cantidad, const char *codigo) {
    int i;
    for (i = 0; i < cantidad; i++) {
        if (strcmp(canciones[i].codigo, codigo) == 0) {
            return i;
        }
    }
    return -1;
}

void registrarCancion(Cancion canciones[], int *cantidad) {
    int opcion, i, clasif_seleccionada;
    char codigo[MAX_CODIGO];
    Cancion nueva;
    
    if (*cantidad >= MAX_CANCIONES) {
        printf("\nError: Limite de canciones alcanzado.\n");
        return;
    }
    
    printf("\n==============================\n");
    printf("REGISTRAR CANCION\n");
    printf("==============================\n");
    
    // Validar codigo
	
	do
	{
		printf("Codigo (1-15 caracteres, sin espacios): ");
		scanf(" %99[^\n]", codigo);

		if(!validarCodigo(canciones, *cantidad, codigo))
		{
			printf("\nError:\n");
			printf("- El codigo ya existe o es invalido.\n");
			printf("- Solo letras y numeros.\n");
			printf("- Sin espacios.\n");
			printf("- Maximo 15 caracteres.\n\n");
		}

	}while(!validarCodigo(canciones, *cantidad, codigo));	
	    
    strcpy(nueva.codigo, codigo);
    
    printf("Titulo: ");
    scanf(" %[^\n]", nueva.titulo);
    
    printf("Compositor: ");
    scanf(" %[^\n]", nueva.compositor);
    
    printf("Artista: ");
    scanf(" %[^\n]", nueva.artista);
    
    // Seleccionar clasificacion
    printf("\nClasificaciones:\n");
    for (i = 0; i < MAX_CLASIFICACIONES; i++) {
        printf("%d. %s\n", i + 1, clasificaciones[i]);
    }
    
    do {
        printf("Seleccione (1-%d): ", MAX_CLASIFICACIONES);
        scanf("%d", &opcion);
    } while (opcion < 1 || opcion > MAX_CLASIFICACIONES);
    
    strcpy(nueva.clasificacion, clasificaciones[opcion - 1]);
    
    // Validar la duracion
    do {
        printf("Duracion en segundos (mayor a 0): ");
        scanf("%d", &nueva.duracion);
        if (nueva.duracion <= 0) {
            printf("Error: La duracion debe ser mayor a 0.\n");
        }
    } while (nueva.duracion <= 0);
    
    // Guardar la cancion
    canciones[*cantidad] = nueva;
    (*cantidad)++;
    
    printf("\nCantidad actual: %d\n", *cantidad);
	printf("\nCancion registrada correctamente!\n");
}

void listarCanciones(Cancion canciones[], int cantidad) {
    int i;
    char duracion_str[20];
    
    if (cantidad == 0) {
        printf("\nNo hay canciones registradas.\n");
        return;
    }
    
    printf("\n==============================\n");
    printf("LISTADO DE CANCIONES\n");
    printf("==============================\n");
    printf("%-12s | %-30s | %-12s | %-20s | %-20s | %-8s\n",
           "Codigo", "Titulo", "Clasificacion", "Compositor", "Artista", "Duracion");
    printf("--------------------------------------------------------------------------------------------------------\n");
    
    for (i = 0; i < cantidad; i++) {
        formatearDuracion(canciones[i].duracion, duracion_str);
        
        printf("%-12s | %-30s | %-12s | %-20s | %-20s | %-8s\n",
               canciones[i].codigo,
               canciones[i].titulo,
               canciones[i].clasificacion,
               canciones[i].compositor,
               canciones[i].artista,
               duracion_str);
    }
}

void buscarCancion(Cancion canciones[], int cantidad) {
    int opcion, i, encontrados;
    char busqueda[100];
    
    if (cantidad == 0) {
        printf("\nNo hay canciones registradas.\n");
        return;
    }
    
    printf("\n==============================\n");
    printf("BUSCAR CANCION\n");
    printf("==============================\n");
    printf("1. Por Codigo\n");
    printf("2. Por Titulo\n");
    printf("3. Por Compositor\n");
    printf("4. Por Artista\n");
    printf("5. Por Clasificacion\n");
    printf("Seleccione: ");
    scanf("%d", &opcion);
    
    printf("Ingrese el valor a buscar: ");
    scanf(" %[^\n]", busqueda);
    
    encontrados = 0;
    printf("\nResultados de la busqueda:\n");
    printf("--------------------------------------------------------------------------------------------------------\n");
    
    for (i = 0; i < cantidad; i++) {
        int coincide = 0;

        switch (opcion) {
            case 1:
                // Antes: strcmp(canciones[i].codigo, busqueda) == 0
                if (str_igual_ignore_case(canciones[i].codigo, busqueda)) coincide = 1;
                break;
            case 2:
                // Antes: strstr(canciones[i].titulo, busqueda) != NULL
                if (str_buscar_ignore_case(canciones[i].titulo, busqueda) != NULL) coincide = 1;
                break;
            case 3:
                // Antes: strstr(canciones[i].compositor, busqueda) != NULL
                if (str_buscar_ignore_case(canciones[i].compositor, busqueda) != NULL) coincide = 1;
                break;
            case 4:
                // Antes: strstr(canciones[i].artista, busqueda) != NULL
                if (str_buscar_ignore_case(canciones[i].artista, busqueda) != NULL) coincide = 1;
                break;
            case 5:
                // Antes: strcmp(canciones[i].clasificacion, busqueda) == 0
                if (str_buscar_ignore_case(canciones[i].clasificacion, busqueda)) coincide = 1;
                break;
            default:
                printf("Opcion no valida.\n");
                return;
        }
        
        if (coincide) {
            mostrarCancion(canciones[i]);
            encontrados++;
        }
    }
    
    printf("\nEncontrados: %d cancion(es).\n", encontrados);
}