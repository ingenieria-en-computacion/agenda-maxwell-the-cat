#ifndef __AGENDA_H__
#define __AGENDA_H__

#define MAX_CONTACTOS 100
#include <ctype.h>

enum TipoTelefono {CASA, MOVIL, OFICINA, OTRO};

enum Mes{
ENERO=1, FEBERO, MARZO, ABRIL, MAYO, JUNIO, JULIO, SEPTIEMBRE, OCTUBRE, NOVIEMBRE, DICIEMBRE
};

typedef struct Persona{
char nombre[30];
char apellido [30];

int dia;
enum Mes mes;

char tipo_contacto [20];
char telefono [20];

int tipo_telefono;
} Contacto;

typedef struct Agenda {
    Contacto contactos[MAX_CONTACTOS];
    int num_contactos; //Lleva la cuenta de cuantos contactos están en la agenda
} Agenda;


void iniciar_agenda(Agenda *agenda);
void agregar_contacto(Agenda *agenda, Contacto c);
void imprimir_agenda(Agenda agenda);
int buscar_contacto(Agenda *agenda, char *nombre);
int buscar_contacto_x_telefono(Agenda *agenda, char telefono[]);
void ordenar_contactos(Agenda *agenda);
void ordenar_contactos_inv(Agenda *agenda);
void mostrar_contacto(Contacto);
void leer_contacto(Contacto *c);
void cargar_contactos(char *filename);
void guardar_contactos(char *filename);

#endif // __AGENDA_H_
