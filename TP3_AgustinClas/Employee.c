#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "UTN.h"



Employee* employee_new(){
    return (Employee*) malloc (sizeof (Employee));
}

Employee* employee_newParametrosStr(char* idStr, char* nombreStr,char* horasTrabajadasStr, char* sueldo){

    Employee* employee;

    employee = employee_newParametros(atoi(idStr), nombreStr, atoi(horasTrabajadasStr), atoi(sueldo));

    return employee;
}

Employee* employee_newParametros(int idStr, char* nombreStr,int horasTrabajadasStr, int sueldo){

    Employee* employee =  employee_new();

    if(employee !=NULL ){
            if(!(employee_setHorasTrabajadas(employee, horasTrabajadasStr) &&
            employee_setId(employee, idStr) &&
            employee_setNombre(employee, nombreStr) &&
            employee_setSueldo(employee, sueldo))){
                employee = NULL;
               }
    }


    return employee;
}

Employee* employee_add(int id){

    Employee* employee = employee_new();
    int contadorOk = 0;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;

    if(utn_getString(nombre, "Ingrese el nombre:", "Error. ", 10) == 0){
        contadorOk++;
    }

    if(utn_getNumeroEntero(&horasTrabajadas, "Ingrese la cantdad de horas trabajadas:", "Error. ", 0, 600 , 10) == 0
        && contadorOk == 1){
            contadorOk++;
        }

    if(utn_getNumeroEntero(&sueldo, "Ingrese el sueldo:", "Error. ", 0, 999999, 10) == 0
        && contadorOk == 2){
            contadorOk++;
        }

    if(contadorOk == 3){
        employee = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
    }else{
        employee = NULL;
    }

    return employee;
}

void employee_list(Employee* employee){
    //No verificamos que sea distinto de NULL porque ya lo hace el controller
    char nombre[128];
    int id;
    int horasTrabajadas;
    int sueldo;

    if(employee_getId(employee, &id) &&
        employee_getNombre(employee, nombre) &&
        employee_getHorasTrabajadas(employee, &horasTrabajadas) &&
        employee_getSueldo(employee, &sueldo)){

        printf("%d  %15s        %d           %d\n", id, nombre, horasTrabajadas, sueldo);
        }

}


int employee_setId(Employee* this,int id){

    int todoOk = 0;

    if(this != NULL && id > 0){
        this->id = id;
        todoOk = 1;
    }

    return todoOk;
}


int employee_getId(Employee* this,int* id){

    int todoOk = 0;

    if(this != NULL && id != NULL){
        *id = this->id;
        todoOk=1;
    }

    return todoOk;
}


int employee_setNombre(Employee* this,char* nombre){

    int todoOk = 0;
    formalizarString(nombre);

    if(this != NULL && nombre != NULL && strlen(nombre) > 1 && strlen(nombre) < 128){

        strcpy(this->nombre, nombre);
        todoOk = 1;
    }

    return todoOk;
}

int employee_getNombre(Employee* this,char* nombre){

    int todoOk = 0;

    if(this != NULL && nombre != NULL ){

        strcpy(nombre,this->nombre);
        todoOk = 1;
    }

    return todoOk;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){

    int todoOk = 0;

    if(this != NULL && horasTrabajadas > 0){

        this->horasTrabajadas = horasTrabajadas;
        todoOk = 1;
    }

    return todoOk;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){

    int todoOk = 0;

    if(this != NULL && horasTrabajadas != NULL){
        *horasTrabajadas = this->horasTrabajadas;
        todoOk=1;
    }

    return todoOk;

}

int employee_setSueldo(Employee* this,int sueldo){

    int todoOk = 0;

    if(this != NULL && sueldo > 0){

        this->sueldo = sueldo;
        todoOk = 1;
    }

    return todoOk;
}

int employee_getSueldo(Employee* this,int* sueldo){

    int todoOk = 0;

    if(this != NULL && sueldo != NULL){
        *sueldo = this->sueldo;
        todoOk=1;
    }

    return todoOk;
}
