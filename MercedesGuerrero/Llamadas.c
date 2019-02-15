#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arraylist.h"
#include "Llamadas.h"
#include "Parser.h"

#define LIBRE 0
#define OCUPADO 1

//CONSTRUCTOR

eLlamada* newLlamada()
{
    eLlamada* nuevaLlamada = (eLlamada*)malloc(sizeof(eLlamada));

    if(nuevaLlamada != NULL)
    {
        nuevaLlamada->id_llamada = 0;
        strcpy(nuevaLlamada->nombre_cliente, "");
        strcpy(nuevaLlamada->email_cliente, "");
        nuevaLlamada->dni_cliente = 0;
        strcpy(nuevaLlamada->producto, "");
        strcpy(nuevaLlamada->observaciones, "");
        nuevaLlamada->isEmpty = LIBRE;
    }

    return nuevaLlamada;
}

//CONSTRUCTOR PARAMETRIZADO

eLlamada* newLlamadaParametrizada(int _id, char* _nombre, char* _email, long int _dni, char* _producto, char* _observaciones)
{
    eLlamada* nuevaLlamada = (eLlamada*)malloc(sizeof(eLlamada));

    if(nuevaLlamada != NULL)
    {
        nuevaLlamada->id_llamada = _id;
        strcpy(nuevaLlamada->nombre_cliente, _nombre);
        strcpy(nuevaLlamada->email_cliente, _email);
        nuevaLlamada->dni_cliente = _dni;
        strcpy(nuevaLlamada->producto, _producto);
        strcpy(nuevaLlamada->observaciones, _observaciones);
        nuevaLlamada->isEmpty = OCUPADO;
    }

    mostrar_unaLlamada(nuevaLlamada);

    return nuevaLlamada;
}

//SETTERS

int set_id(eLlamada* unaLlamada, int valor)
{
    int ret = 0;
    if(unaLlamada!=NULL && valor>0)
    {
        unaLlamada->id_llamada= valor;
        ret = 1;
    }
    return ret;
}

int set_nombre(eLlamada* unaLlamada, char* _nombre)
{
    int ret = 0;
    if(unaLlamada!=NULL && _nombre!=NULL)
    {
        strcpy(unaLlamada->nombre_cliente, _nombre);
        ret = 1;
    }
    return ret;
}

int set_email(eLlamada* unaLlamada, char* _email)
{
    int ret = 0;
    if(unaLlamada!=NULL && _email!=NULL)
    {
        strcpy(unaLlamada->email_cliente, _email);
        ret = 1;
    }
    return ret;
}

int set_dni(eLlamada* unaLlamada, long int valor)
{
    long int ret = 0;
    if(unaLlamada!=NULL && valor>0)
    {
        unaLlamada->dni_cliente= valor;
        ret = 1;
    }
    return ret;
}

int set_producto(eLlamada* unaLlamada, char* _producto)
{
    int ret = 0;
    if(unaLlamada!=NULL && _producto!=NULL)
    {
        strcpy(unaLlamada->producto, _producto);
        ret = 1;
    }
    return ret;
}

int set_isEmpty(eLlamada* unaLlamada, int valor)
{
    int ret = 0;
    if(unaLlamada!=NULL && valor>0)
    {
        unaLlamada->isEmpty= valor;
        ret = 1;
    }
    return ret;
}

//GETTERS
int get_id(eLlamada* unaLlamada)
{
    int valor = -1;
    if(unaLlamada!=NULL)
    {
        valor= unaLlamada->id_llamada;
    }
    return valor;
}

char* get_nombre(eLlamada* unaLlamada)
{
    char* _nombre;
    if(unaLlamada!=NULL)
    {
       _nombre= unaLlamada->nombre_cliente;
    }
    return _nombre;
}

char* get_email(eLlamada* unaLlamada)
{
    char* _email;
    if(unaLlamada!=NULL)
    {
       _email= unaLlamada->email_cliente;
    }
    return _email;
}

int get_dni(eLlamada* unaLlamada)
{
    long int valor = -1;
    if(unaLlamada!=NULL)
    {
        valor= unaLlamada->dni_cliente;
    }
    return valor;
}

char* get_producto(eLlamada* unaLlamada)
{
    char* _producto;
    if(unaLlamada!=NULL)
    {
       _producto= unaLlamada->producto;
    }
    return _producto;
}

char* get_observaciones(eLlamada* unaLlamada)
{
    //puts(unaLlamada->observaciones);
    char* _obs;
    if(unaLlamada!=NULL)
    {
       _obs= unaLlamada->observaciones;
    }
    return _obs;
}

int get_isEmpty(eLlamada* unaLlamada)
{
    int valor = -1;
    if(unaLlamada!=NULL)
    {
        valor= unaLlamada->isEmpty;
    }
    return valor;
}

//----------------------------------------------------------------------------------

void mostrar_unaLlamada(eLlamada* unaLlamada)
{
    //puts(unaLlamada->observaciones);
  printf(" %4d  %14s  %36s    %11ld     %18s    %20s\n\n", get_id(unaLlamada), get_nombre(unaLlamada), get_email(unaLlamada), get_dni(unaLlamada), get_producto(unaLlamada), get_observaciones(unaLlamada));
}

void mostrarLlamadas(ArrayList* lista)
{
    eLlamada* unaLlamada;
    system("cls");
    printf("----------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("   ID   |       Nombre      |             eMail              |          DNI       |         Producto      |        Observaciones\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------------------\n\n");
    for(int i=0; i< lista->len(lista); i++)
    {
        unaLlamada= (eLlamada*)lista->get(lista, i);
        if(unaLlamada->isEmpty == OCUPADO)
        {
            mostrar_unaLlamada(unaLlamada);
        }
    }
    printf("----------------------------------------------------------------------------------------------------------------------------------------\n\n");
}

int buscarLlamada(ArrayList* lista, int id)
{
    int indice = -1;
    eLlamada* unaLlamada;

    for(int i=0; i< lista->len(lista); i++)
    {
        unaLlamada = (eLlamada*)lista->get(lista, i);
        if( get_id(unaLlamada) == id && unaLlamada->isEmpty == OCUPADO)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int getInt(char* mensaje)
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);

    return auxiliar;
}

int getLong(char* mensaje)
{
    long int auxiliar;
    printf("%s",mensaje);
    scanf("%ld",&auxiliar);

    return auxiliar;
}

int compararNombre_yDNI(void* x, void* y)
{
    eLlamada* cliente1 = (eLlamada*)x;
    eLlamada* cliente2 = (eLlamada*)y;
    int retorno;

    if(strcmp(get_nombre(cliente1), get_nombre(cliente2)) && get_dni(cliente1) == get_dni(cliente2))
    {
        retorno = 0;
    }
    else
    {
        retorno = -1;
    }

    return retorno;
}

int filtrarPorID_Par(eLlamada* unaLlamada)
{
    int ret_aux= -1;
    if(get_id(unaLlamada)% 2 == 0)
    {
        ret_aux= 1;
    }
    return ret_aux;
}

int cliente_mas_llamadas(eLlamada* unaLlamada, eLlamada* otraLlamada)
{
    int ret_aux= -1;
    if(get_id(unaLlamada)% 2 == 0)
    {
        ret_aux= 1;
    }
    return ret_aux;
}

int compararID(void* x, void* y)
{
    eLlamada* llamada1 = (eLlamada*)x;
    eLlamada* llamada2 = (eLlamada*)y;
    int retorno;

    if(get_id(llamada1) == get_id(llamada2))
    {
        retorno = 0;
    }
    else if( get_id(llamada1) > get_id(llamada2))
    {
        retorno = 1;
    }
    else
    {
        retorno = -1;
    }

    return retorno;
}
