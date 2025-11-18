#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "agenda.h"

void iniciar_agenda(Agenda *agenda) {
    agenda->num_contactos = 0;
}

void agregar_contacto(Agenda *agenda, Contacto c) {
    if (agenda->num_contactos >= MAX_CONTACTOS) {
        printf("La agenda está llena.\n");
        return;
    }
    agenda->contactos[agenda->num_contactos++] = c;
    ordenar_contactos(agenda);
}

int buscar_contacto(Agenda *agenda, char *nombre) {
    for (int i = 0; i < agenda->num_contactos; i++)
        if (strcmp(agenda->contactos[i].nombre, nombre) == 0)
            return i;
    return -1;
}

int buscar_contacto_x_telefono(Agenda *agenda, char telefono[]) {
    for (int i = 0; i < agenda->num_contactos; i++)
        if (strcmp(agenda->contactos[i].telefono, telefono) == 0)
            return i;
    return -1;
}

void ordenar_contactos(Agenda *a) {
    Contacto temp;
    for (int i = 0; i < a->num_contactos - 1; i++)
        for (int j = 0; j < a->num_contactos - i - 1; j++)
            if (strcmp(a->contactos[j].nombre, a->contactos[j+1].nombre) > 0) {
                temp = a->contactos[j];
                a->contactos[j] = a->contactos[j+1];
                a->contactos[j+1] = temp;
            }
}

void ordenar_contactos_inv(Agenda *a) {
    Contacto temp;
    for (int i = 0; i < a->num_contactos - 1; i++)
        for (int j = 0; j < a->num_contactos - i - 1; j++)
            if (strcmp(a->contactos[j].nombre, a->contactos[j+1].nombre) < 0) {
                temp = a->contactos[j];
                a->contactos[j] = a->contactos[j+1];
                a->contactos[j+1] = temp;
            }
}

void mostrar_contacto(Contacto c) {
    char *nombremes[] = {
        "", "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio",
        "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"
    };

    char *tipotel[] = {"Casa", "Movil", "Oficina", "Otro"};

    printf("---------------------------\n");
    printf("Nombre: %s %s\n", c.nombre, c.apellido);
    printf("Nacimiento: %d de %s\n", c.dia, nombremes[c.mes]);
    printf("Tipo de contacto: %s\n", c.tipo_contacto);
    printf("Telefono: %s\n", c.telefono);
    printf("Tipo de telefono: %s\n", tipotel[c.tipo_telefono]);
}

void leer_contacto(Contacto *c) {
    char texto_mes[20];

    printf("Nombre: ");
    fgets(c->nombre, 30, stdin);
    c->nombre[strcspn(c->nombre, "\n")] = 0;

    printf("Apellido: ");
    fgets(c->apellido, 30, stdin);
    c->apellido[strcspn(c->apellido, "\n")] = 0;

    printf("Dia de nacimiento: ");
    scanf("%d", &c->dia);
    getchar();

    printf("Mes de nacimiento (numero o nombre): ");
    fgets(texto_mes, sizeof(texto_mes), stdin);
    texto_mes[strcspn(texto_mes, "\n")] = 0;

    if (isdigit(texto_mes[0]))
        c->mes = atoi(texto_mes);
    else {
        if      (!strcasecmp(texto_mes,"enero")) c->mes = ENERO;
        else if (!strcasecmp(texto_mes,"febrero")) c->mes = FEBRERO;
        else if (!strcasecmp(texto_mes,"marzo")) c->mes = MARZO;
        else if (!strcasecmp(texto_mes,"abril")) c->mes = ABRIL;
        else if (!strcasecmp(texto_mes,"mayo")) c->mes = MAYO;
        else if (!strcasecmp(texto_mes,"junio")) c->mes = JUNIO;
        else if (!strcasecmp(texto_mes,"julio")) c->mes = JULIO;
        else if (!strcasecmp(texto_mes,"agosto")) c->mes = AGOSTO;
        else if (!strcasecmp(texto_mes,"septiembre")) c->mes = SEPTIEMBRE;
        else if (!strcasecmp(texto_mes,"octubre")) c->mes = OCTUBRE;
        else if (!strcasecmp(texto_mes,"noviembre")) c->mes = NOVIEMBRE;
        else if (!strcasecmp(texto_mes,"diciembre")) c->mes = DICIEMBRE;
        else {
            printf("Mes invalido, usando ENERO.\n");
            c->mes = ENERO;
        }
    }

    printf("Tipo de contacto: ");
    fgets(c->tipo_contacto, 20, stdin);
    c->tipo_contacto[strcspn(c->tipo_contacto, "\n")] = 0;

    printf("Telefono: ");
    fgets(c->telefono, 20, stdin);
    c->telefono[strcspn(c->telefono, "\n")] = 0;

    printf("Tipo de telefono (0=CASA,1=MOVIL,2=OFICINA,3=OTRO): ");
    scanf("%d", &c->tipo_telefono);
    getchar();
}

void imprimir_agenda(Agenda agenda) {
    for (int i = 0; i < agenda.num_contactos; i++)
        mostrar_contacto(agenda.contactos[i]);
}

void guardar_contactos(char *filename, Agenda agenda) {
    FILE *f = fopen(filename, "w");
    if (!f) {
        printf("Error al guardar archivo.\n");
        return;
    }

    for (int i = 0; i < agenda.num_contactos; i++) {
        Contacto c = agenda.contactos[i];
        fprintf(f, "%s|%s|%d|%d|%s|%s|%d\n",
            c.nombre, c.apellido, c.dia, c.mes,
            c.tipo_contacto, c.telefono, c.tipo_telefono);
    }

    fclose(f);
    printf("Agenda guardada correctamente.\n");
}

void cargar_contactos(char *filename, Agenda *agenda) {
    FILE *f = fopen(filename, "r");
    if (!f) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    agenda->num_contactos = 0;
    Contacto c;

    while (fscanf(f, "%[^|]|%[^|]|%d|%d|%[^|]|%[^|]|%d\n",
                  c.nombre, c.apellido, &c.dia, (int*)&c.mes,
                  c.tipo_contacto, c.telefono, &c.tipo_telefono) == 7) {

        agenda->contactos[agenda->num_contactos++] = c;
    }

    fclose(f);
    printf("Agenda cargada correctamente.\n");
}


