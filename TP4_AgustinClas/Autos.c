#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Autos.h"
#include "UTN.h"

eAuto* auto_new(){
    eAuto* this = (eAuto*) malloc (sizeof(eAuto));

    return this;
}

eAuto* auto_newParametrosStr(char* id, char* marca,char* modelo, char* anio, char* precio){

    eAuto* auxAuto;

    auxAuto = auto_newParametros(atoi(id), marca, modelo, atoi(anio), atof(precio));

    return auxAuto;
}

eAuto* auto_newParametros(int id, char* marca,char* modelo, int anio, float precio){

    eAuto* this = auto_new();

    if(this != NULL ){
            //en caso de que algun set devuelva 0 le asignamos el valor NULL a la estructura que devolvera la funcion
            if(!(auto_setId(this, id) &&
            auto_setAnio(this, anio) &&
            auto_setMarca(this,marca) &&
            auto_setModelo(this,modelo) &&
            auto_setPrecio(this, precio))){
                this = NULL;
            }
    }


    return this;
}

int auto_setId(eAuto* this,int id){

    int todoOk = 0;

    if(this != NULL && id > 0){
        this->id = id;
        todoOk = 1;
    }

    return todoOk;
}


int auto_getId(eAuto* this,int* id){

    int todoOk = 0;

    if(this != NULL && id != NULL){
        *id = this->id;
        todoOk=1;
    }

    return todoOk;
}

int auto_setMarca(eAuto* this,char* marca){

    int todoOk = 0;
    formalizarString(marca);

    if(this != NULL && marca != NULL && strlen(marca) > 1 && strlen(marca) < 25){

        strcpy(this->marca, marca);
        todoOk = 1;
    }

    return todoOk;
}

int auto_getMarca(eAuto* this,char* marca){

    int todoOk = 0;

    if(this != NULL && marca != NULL ){

        strcpy(marca,this->marca);
        todoOk = 1;
    }

    return todoOk;
}

int auto_setModelo(eAuto* this,char* modelo){

    int todoOk = 0;
    formalizarString(modelo);

    if(this != NULL && modelo != NULL && strlen(modelo) > 1 && strlen(modelo) < 25){

        strcpy(this->modelo, modelo);
        todoOk = 1;
    }

    return todoOk;
}

int auto_getModelo(eAuto* this,char* modelo){

    int todoOk = 0;

    if(this != NULL && modelo != NULL ){

        strcpy(modelo,this->modelo);
        todoOk = 1;
    }

    return todoOk;
}

int auto_setAnio(eAuto* this,int anio){

    int todoOk = 0;

    if(this != NULL && anio > 0){
        this->anio = anio;
        todoOk = 1;
    }

    return todoOk;
}


int auto_getAnio(eAuto* this,int* anio){

    int todoOk = 0;

    if(this != NULL && anio != NULL){
        *anio = this->anio;
        todoOk=1;
    }

    return todoOk;
}

int auto_setPrecio(eAuto* this,float precio){

    int todoOk = 0;

    if(this != NULL && precio > 0){
        this->precio = precio;
        todoOk = 1;
    }

    return todoOk;
}


int auto_getPrecio(eAuto* this,float* precio){

    int todoOk = 0;

    if(this != NULL && precio != NULL){
        *precio = this->precio;
        todoOk=1;
    }

    return todoOk;
}

eAuto* auto_Add(int id){
    eAuto* auxAuto = auto_new();
    int contadorOk = 0;
    char marca[25];
    char modelo[25];
    int anio;
    float precio;

    if(utn_getString(marca, "Ingrese la marca:", "Error. ", 10) == 0){
        contadorOk++;
    }

    if(utn_getString(modelo, "Ingrese el modelo:", "Error. ",10) == 0
        && contadorOk == 1){
            contadorOk++;
        }

    if(utn_getNumeroEntero(&anio, "Ingrese el anio:", "Error. ", 1930, 2020, 10) == 0
        && contadorOk == 2){
            contadorOk++;
        }

    if(utn_getNumeroFlotante(&precio, "Ingrese el Precio:", "Error. ", 10000, 1000000, 10) == 0
        && contadorOk == 3){
            contadorOk++;
        }

    //Si contadorOk es igual a 4 significa que fueron tomados todos los datos correctamente
    if(contadorOk == 4){
        auxAuto = auto_newParametros(id, marca, modelo, anio, precio);
    }else{
        auxAuto = NULL;
    }

    return auxAuto;

}

void listarAutos(LinkedList* this){

    eAuto* auxAuto;

    //verficamos que el linkedlist pasado no sea NULL
    if(this!=NULL){
        printf("Id          Marca              Modelo       Anio       Precio\n");
        for(int i=0; i<ll_len(this);i++){
            auxAuto = (eAuto*) ll_get(this, i);
            if(auxAuto != NULL){
                listarAuto(auxAuto);
            }
        }
    }

}

void listarAuto(eAuto* auxAuto){

    int id;
    int anio;
    char marca[25];
    char modelo[25];
    float precio;

    if(auto_getId(auxAuto,&id) &&
        auto_getMarca(auxAuto, marca) &&
        auto_getModelo(auxAuto, modelo) &&
        auto_getAnio(auxAuto,&anio) &&
        auto_getPrecio(auxAuto, &precio)){
            printf("%3d %15s    %15s     %d      %.2f\n", id,  marca, modelo, anio, precio);
        }
}
