#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Arraylist.h"
#include "Llamadas.h"
#include "Parser.h"

#define JUNIOR 2
#define ESTANDARD 1
#define EXPERTO 0

#define LIBRE 0
#define OCUPADO 1

int menu();
void presionarContinuar();

int main()
{
    char seguir = 's';
    ArrayList* lista = al_newArrayList();
    ArrayList* subListaFiltrada = al_newArrayList();

    //int respuesta;

    if(lista == NULL)
    {
        printf("\nError: can't allocate memory");
        exit(1);
    }

    do
    {
        switch(menu())
        {

        case 1:
            parsearLlamadas("data.csv", lista);
            printf("\nSe cargaron las llamadas\n");
            presionarContinuar();
            break;
        case 2:
            lista->sort(lista, compararID, 0);
            mostrarLlamadas(lista);
            presionarContinuar();
            break;
        case 3:
            //lista->sort(lista, compararNombre_yDNI, 0);
            //mostrarLlamadas(lista);
            //mostrarLlamadas(lista->filter(lista, ));
            presionarContinuar();
            break;
        case 4:

            presionarContinuar();
            break;
        case 5:
            subListaFiltrada= lista->filter(lista, filtrarPorID_Par);
            if(guardarArchivoLlamadas("ID Par.csv", subListaFiltrada)==1)
            {
                mostrarLlamadas(subListaFiltrada);
                printf("\n\n Se creo el archivo de llamadas ID par\n\n");
            }
            presionarContinuar();
            break;
        case 6:

            presionarContinuar();
            break;
        case 7:

            presionarContinuar();
            break;
        case 8:

            presionarContinuar();
            break;
        case 9:
            seguir = 'n';
            //guardarEmpleados("vendedores.csv", lista);
            break;
        }

    }while(seguir == 's');

    return 0;
}

int menu()
{
    int opcion;
    system("cls");
    printf("\n      ***Menu de Opciones***\n\n");
    printf("   1- Cargar archivo\n");
    printf("   2- Imprimir llamadas\n");
    printf("   3- Imprimir estadistica\n");
    printf("   4- Generar archivo de clientes\n");
    printf("   5- Generar archivo de llamadas con id par\n");
    printf("   6- MODIFICAR\n");
    printf("   7- ELIMINAR\n");
    printf("   8- Ordenar\n");
    printf("   9- Salir\n");
    printf("\n   Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

void presionarContinuar()
{
    printf("\nPresione cualquier tecla para continuar ");
    getch();
}
