#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stlib.h>
#include "agenda.h"

/**
 * Esta función se encarga de iniciar el número de contactos a cero
 */
void iniciar_agenda(Agenda *agenda){
    agenda->num_contactos = 0;
}
/**
 * Esta función sirve para agregar un contacto nuevo en la agenda
 */
void agregar_contacto(Agenda *agenda, Contacto c){
    if(agenda->num_contactos >= MAX_CONTACTOS){
        printf("La agenda esta llena.\n");
        return;
    }
agenda->contactos[agenda->num_contactos++] = c;
ordenar_contactos(agenda);
}


/**
 * Esta función sirve para buscar un contacto por nombre en la agenda y retorna la posición del contacto si exisite
 * En caso contrario retorna -1
 */
int buscar_contacto(Agenda *agenda, char *nombre){
    for(int i = 0; i < agenda->num_contactos; i++){
        if(strcmp(agenda->contactos[i].nombre, nombre) ==0)
            return i;
    }
    return -1;
}


/**
 * Esta función  sirve para buscar un contacto por su número de telefono en la agenda
 */
int buscar_contacto_x_telefono(Agenda *agenda, char telefono[]){
    for(int i=0; i < agenda->num_contactos; i++){
        if(strcmp(agenda->contactos[i].telefono, telefono) ==0)
            return i;
    }
    return -1;
}


/**
 * Esta función sirve para ordenar los contactos por nombres de forma ascendente
 */
void ordenar_contactos(Agenda *a){
    Contacto temp;
    for(int i = 0; i < a->num_contactos -1; i++)
        for(int j=0; j < a->num_contactos-i-1; j++)
            if(strcmp(a->contactos[j].nombre, a->contactos[j+1].nombre)>0){
                temp = a->contactos[j];
                a->contactos[j] = a->contactos[j+1];
                a->contactos[j+1] = temp;
            }
}

/**
 * Esta función sirve para ordenar los contactos por nombres de forma descendente
 */
void ordenar_contactos_inv(Agenda *a){
    Contacto temp;
    for(int i = 0; i < a->num_contactos-1; i++)
        for(int j=0; j < a->num_contactos-i-1; j++)
            if(strcmp(a->contacto[j].nombre, a->contactos[j+1].nombre) < 0){
                temp = a->contactos[j];
                a->contactos[j+1] = temp;
        }
}


/**
 * Función auxiliar para imprimir un contacto
 */
void mostrar_contacto(Contacto){

    char *nombremes[] = {
        "", "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"
};

    char *tipotel[] = {"Casa", "Movil", "Oficina", "Otro"};
    printf("-------------------------\n");
    printf("Nombre: %s %s\n", c.nombre, c.apellido);
    printf("Nacimiento: %d de %s\n", c.dia, nombremes[c.mes]);
    printf("Tipo de contacto: %s\n", c.tipo_contacto);
    printf("Telefono: %s\n", c.telefono);
    printf("Tipo de telefono: %s\n", tipotel[c.tipo_telefono]);
}


/**
 * Función auxiliar para leer un contacto
 */
void leer_contacto(Contacto *c){

}

/**
 * Función que imprime todos los contactos de la agenda en pantalla
 */
void imprimir_agenda(Agenda agenda){

}

/**
 * Función que sirve para cargar contactos escritos en un archivo a la agenda
 */
void cargar_contactos(char *filename, Agenda *agenda){

}


/**
 * Función que sirve para guardar todos los contactos de la agenda en un archivo
 */
void guardar_contactos(char *filename, Agenda agenda){

}
