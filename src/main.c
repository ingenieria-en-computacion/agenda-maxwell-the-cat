#include <stdio.h>
#include <string.h>
#include "agenda.h"

int main(){
  Agenda agenda;
  iniciar_agenda(&agenda);

  int opcion;
  char nombre_buscar[30];
  char telefono_buscar[20];

  const char *archivo="agenda.txt";

  do{
    printf("\n---MENU AGENDA---\n");
    printf("1. Agregar contacto\n");
    printf("2. Mostrar agenda\n");
    printf("3. Buscar por nombre\n");
    printf("4. Buscar por telefono\n");
    printf("5. Guardar agenda\n");
    printf("6. Cargar agenda\n");
    printf("7. Ordenar A-Z\n");
    printf("8. Ordenar Z-A\n");
    printf("0. Salir\n");
    printf("Opcion: ");
    scanf("%d",&opcion);
    getchar();

    switch(opcion){

    case 1:{
      contacto c;
      leer_contacto(&agenda, c);
      agregar_contacto(&agenda, c);
      break;
    }

    case 2:
      imprimir_agenda(agenda);
      break;

    case 3:
      printtf("Nombre a buscar: ");
      fegts(nombre_buscar, 30, stdin);
      nombre_buscar[strcspn(nombre_buscar, "\n")]=0;

      int pos;
      pos = buscar_contacto(&agenda, nombre_buscar);

      if (pos >= 0)
        mostrar_contacto(agenda.contactos[pos]);
      else
        printf("No se encontro el contacto.\n");
    break;

    case 4:
       printf("Telefono a buscar: ");
          fgets(telefono_buscar, 20, stdin);
          telefono_buscar[strcspn(telefono_buscar, "\n")] = 0;

           pos = buscar_contacto_x_telefono(&agenda, telefono_buscar);

          if (pos >= 0)
              mostrar_contacto(agenda.contactos[pos]);
          else
              printf("No se encontro el numero.\n");
          break;

      case 5:
          guardar_contactos((char *)archivo, agenda);
          break;

      case 6:
          cargar_contactos((char *)archivo, &agenda);
          break;

      case 7:
          ordenar_contactos(&agenda);
          printf("Contactos ordenados A-Z.\n");
          break;

      case 8:
          ordenar_contactos_inv(&agenda);
          printf("Contactos ordenados Z-A.\n");
          break;

      case 0:
          printf("Saliendo...\n");
          break;

        default:
          printf("Opcion no valida.\n");
        }

    } while (opcion != 0);

    return 0;
}



    

