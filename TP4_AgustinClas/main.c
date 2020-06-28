#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "UTN.h"
#include "ControllerAutos.h"

int menu(void);

int main()
{
    LinkedList* listaAutos = ll_newLinkedList();
    int option;

    do{
        option = menu();
        switch(option){
            case 1:
                if(controller_loadFromText("dataAuto.csv", listaAutos) == 1){
                    printf("Autos cargados correctamente!\n");
                }else{
                    printf("No se pudieron cargar los autos\n\n");
                }
                break;
            case 2:
                if(!ll_isEmpty(listaAutos)){
                    if(controller_addAuto(listaAutos)){
                        printf("Auto cargado correctamente\n\n");
                    }else{
                        printf("No se pudo cargar el auto\n\n");
                    }
                }else{
                    printf("Primero cargue los autos desde el archivo\n");
                }
                break;
            case 3:
                if(!ll_isEmpty(listaAutos)){
                    if(controller_removeAuto(listaAutos)){
                        printf("Auto dado de baja correctamente\n\n");
                    }else{
                        printf("No se pudo dar de baja el auto\n\n");
                    }
                }else{
                    printf("Primero cargue los autos desde el archivo\n");
                }
                break;
            case 4:
                if(!ll_isEmpty(listaAutos)){
                    if(controller_editAutos(listaAutos)){
                        printf("Auto modificado correctamente\n\n");
                    }else{
                        printf("No se pudo modificar el auto\n\n");
                    }
                }else{
                    printf("Primero cargue los autos desde el archivo\n");
                }
                break;
            case 5:
                if(!ll_isEmpty(listaAutos)){
                    controller_listAutos(listaAutos);
                }else{
                    printf("Primero cargue los autos desde el archivo\n");
                }
                break;
            case 6:
                if(!ll_isEmpty(listaAutos)){
                    if(controller_recargarAutos(listaAutos, "dataAuto.csv")){
                        printf("Lista de autos recargada correctamente\n");
                    }else{
                        printf("No se recargar los datos\n\n");
                    }
                }else{
                    printf("No hay datos cargados en el sistema\n");
                }

                break;
            case 7:
                if(!ll_isEmpty(listaAutos)){
                    controller_topAutos(listaAutos);
                    system("cls");
                }else{
                    printf("No hay datos cargados en el sistema\n");
                }
                break;
            case 8:
                if(!ll_isEmpty(listaAutos)){
                    if(controller_manipularLista(listaAutos)){
                    printf("Lista modificada\n");
                    }else{
                    printf("No se pudo modificar la lista\n");
                    }
                }else{
                    printf("No hay datos cargados en el sistema\n");
                }
                break;
            case 9:
                if(!ll_isEmpty(listaAutos)){
                    if(controller_saveAsText("dataAutos.csv",listaAutos)){
                    printf("Lista guardada con exito\n");
                    }else{
                    printf("No se pudo guardar la lista\n");
                    }
                }else{
                    printf("No hay datos cargados en el sistema\n");
                }
                break;
        }
    }while(option != 10);
    return 0;

    ll_deleteLinkedList(listaAutos);
}

int menu(void){

    int opcion = 10;

    printf("*****AUTOS******\n1. Cargar los autos desde el archivo\n");
    printf("2. Aniadir auto\n");
    printf("3. Remover auto\n");
    printf("4. Modificar auto\n");
    printf("5. Listar autos\n");
    printf("6. Recargar datos del archivo\n");
    printf("7. Crear top\n");
    printf("8. Manipular lista\n");
    printf("9. Guardar las datos en el archivo\n");
    printf("10. Salir\n");

    if(utn_getNumeroEntero(&opcion, "Ingrese una opcion: ", "Error. ", 1, 10, 10) == -1){
        printf("Supero la cantidad de reintentos permitida. Usted saldra del programa\n");
    }

    return opcion;

}

