#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arraylist.h"
#include "Llamadas.h"
#include "Parser.h"

#define LIBRE 0
#define OCUPADO 1

void parsearLlamadas(char* path, ArrayList* listaLlamadas)
{

    FILE* f;
    eLlamada* nuevaLlamada;

    int cant;
    char buffer[6][228];

    f = fopen(path, "r");

    if(f != NULL && listaLlamadas != NULL)
    {

        fscanf(f,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5]);

        while( !feof(f))
        {

            cant =  fscanf(f,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5]);

            if(cant == 6)
            {
                nuevaLlamada = newLlamada();

                if(nuevaLlamada != NULL)
                {
                    nuevaLlamada->id_llamada = atoi(buffer[0]);
                    strcpy(nuevaLlamada->nombre_cliente, buffer[1]);
                    strcpy(nuevaLlamada->email_cliente, buffer[2]);
                    nuevaLlamada->dni_cliente =  atol(buffer[3]);
                    strcpy(nuevaLlamada->producto, buffer[4]);
                    strncpy(nuevaLlamada->observaciones, buffer[5], 30);

                    nuevaLlamada->isEmpty = set_isEmpty(nuevaLlamada, OCUPADO);

                    listaLlamadas->add(listaLlamadas, nuevaLlamada);

                }
            }
            else
            {
                break;
            }
        }

        fclose(f);
    }

}

int guardarArchivoLlamadas(char* path, ArrayList* listaLlamadas)
{
    int retorno=-1;
    FILE* f;

    f = fopen(path, "w");
    eLlamada* unaLlamada;

    if(f != NULL)
    {

        fprintf(f, "ID,Nombre,eMail,DNI,producto,observaciones\n");

        for(int i=0; i < listaLlamadas->len(listaLlamadas); i++)
        {
            unaLlamada = (eLlamada*)listaLlamadas->get(listaLlamadas, i);
            if(get_isEmpty(unaLlamada)== OCUPADO)
            {
                fprintf(f,"%d,%s,%s,%ld,%s,%s\n", get_id(unaLlamada), get_nombre(unaLlamada), get_email(unaLlamada), get_dni(unaLlamada), get_producto(unaLlamada), get_observaciones(unaLlamada));
            }
        }
        retorno= 1;
        fclose(f);
    }
    return retorno;
}
