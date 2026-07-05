#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>

#include "canciones.h"
#include "archivos.h"
#include "reportes.h"

int main() {
    // Para que se muestren las tildes
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "");
    
    Cancion canciones[MAX_CANCIONES];
    int cantidad = 0;
    
    // Cargar archivo al inicio
    cargarArchivo(canciones, &cantidad);
    
    int opcion;
    
    do {
        printf("\n");
        printf("--------------------------------------------------------\n");
        printf("           BIBLIOTECA MUSICAL\n");
        printf("           MENU DE OPCIONES\n");
        printf("--------------------------------------------------------\n");
        printf("1. Registrar cancion\n");
        printf("2. Listar canciones\n");
        printf("3. Buscar cancion\n");
        printf("4. Actualizar cancion\n");
        printf("5. Eliminar cancion\n");
        printf("6. Calculos requeridos\n");
        printf("7. Guardar cambios en archivo plano .csv\n");
        printf("8. Salir (guardar automaticamente)\n");
        printf("--------------------------------------------------------\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        
        switch(opcion) {
            case 1:
                registrarCancion(canciones, &cantidad);
                break;
            case 2:
                listarCanciones(canciones, cantidad);
                break;
            case 3:
                buscarCancion(canciones, cantidad);
                break;
            case 4:
                actualizarCancion(canciones, cantidad);
                break;
            case 5:
                eliminarCancion(canciones, &cantidad);
                break;
            case 6: {
                int subopcion;
                do {
                    printf("\n--------------------------------------------------------\n");
                    printf("           CALCULOS REQUERIDOS\n");
                    printf("--------------------------------------------------------\n");
                    printf("1. Mostrar duracion de una cancion\n");
                    printf("2. Calcular tiempo total de reproduccion\n");
                    printf("3. Identificar la cancion mas larga\n");
                    printf("4. Identificar la cancion mas corta\n");
                    printf("5. Cantidad de canciones por clasificacion\n");
                    printf("6. Duracion promedio\n");
                    printf("7. Clasificacion con mas canciones\n");
                    printf("8. Tiempo total por clasificacion\n");
                    printf("9. Volver al menu principal\n");
                    printf("--------------------------------------------------------\n");
                    printf("Seleccione: ");
                    scanf("%d", &subopcion);
                    
                    switch(subopcion) {
                        case 1:
                            mostrarDuracion(canciones, cantidad);
                            break;
                        case 2:
                            tiempoTotal(canciones, cantidad);
                            break;
                            case 3:
                            cancionMasLarga(canciones, cantidad);
                            break;
                        case 4:
                            cancionMasCorta(canciones, cantidad);
                            break;
                        case 5:
                            cantidadPorClasificacion(canciones, cantidad);
                            break;
                        case 6:
                            promedioDuracion(canciones, cantidad);
                            break;
                        case 7:
                            clasificacionMayor(canciones, cantidad);
                            break;
                        case 8:
                            tiempoPorClasificacion(canciones, cantidad);
                            break;
                        case 9:
                            printf("\nVolviendo al menu principal...\n");
                            break;
     
                        default:
                            printf("\nOpción no valida.\n");
                    }
                    
                    if (subopcion != 9) {
                        printf("\nPresione ENTER para continuar...");
                        getchar();
                        getchar();
                        system("cls");
                    }
                } while (subopcion != 9);
                break;
            }
            case 7:
                guardarArchivo(canciones, cantidad);
                break;
            case 8:
                printf("\nGuardando cambios y saliendo...\n");
                guardarArchivo(canciones, cantidad);
                printf("\nGracias por utilizar el sistema de biblioteca musical.\n");
                break;
            default:
                printf("\nOpcion no valida.\n");
        }
        
        if (opcion != 8) {
            printf("\nPresione ENTER para continuar...");
            getchar(); // consume el salto de linea
            getchar(); // espera Enter
            system("cls");
        }
        
    } while(opcion != 8);
    
    return 0;
}
