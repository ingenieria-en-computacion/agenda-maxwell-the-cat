#ifndef __AGENDA_H__
#define __AGENDA_H__

#define MAX_CONTACTOS 100

// Tipos de datos
enum TipoTelefono { CASA, MOVIL, OFICINA, OTRO };

enum Mes {
<<<<<<< HEAD
    ENERO = 1, FEBRERO, MARZO, ABRIL, MAYO, JUNIO,
=======
    ENERO=1, FEBRERO, MARZO, ABRIL, MAYO, JUNIO,
>>>>>>> f5e003fec65f22cfe3195d5881888d995853c2b5
    JULIO, AGOSTO, SEPTIEMBRE, OCTUBRE, NOVIEMBRE, DICIEMBRE
};

typedef struct Persona {
    char nombre[30];
    char apellido[30];

    int dia;
    enum Mes mes;

    char tipo_contacto[20];
    char telefono[20];

    int tipo_telefono;
} Contacto;

typedef struct Agenda {
    Contacto contactos[MAX_CONTACTOS];
    int num_contactos;
<<<<<<< HEAD
} Agenda; age 

// Prototipos correctos
=======
} Agenda;

>>>>>>> f5e003fec65f22cfe3195d5881888d995853c2b5
void iniciar_agenda(Agenda *agenda);
void agregar_contacto(Agenda *agenda, Contacto c);
void imprimir_agenda(Agenda agenda);
int buscar_contacto(Agenda *agenda, char *nombre);
int buscar_contacto_x_telefono(Agenda *agenda, char telefono[]);
void ordenar_contactos(Agenda *agenda);
void ordenar_contactos_inv(Agenda *agenda);
void mostrar_contacto(Contacto c);
void leer_contacto(Contacto *c);
<<<<<<< HEAD
void guardar_contactos(char *filename, Agenda agenda);
void cargar_contactos(char *filename, Agenda *agenda);

#endif

=======
void cargar_contactos(char *filename, Agenda *agenda);
void guardar_contactos(char *filename, Agenda agenda);

#endif
>>>>>>> f5e003fec65f22cfe3195d5881888d995853c2b5
