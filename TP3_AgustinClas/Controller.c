#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "UTN.h"


int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    FILE* dataFile;

    system("cls");

    if(pArrayListEmployee != NULL){
        dataFile = fopen(path, "r");

        if(dataFile != NULL){
            if(parser_EmployeeFromText(dataFile, pArrayListEmployee) == 1){
                retorno = 1;
            }
        }
        fclose(dataFile);
    }
    return retorno;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    FILE* dataFile;

    system("cls");

    if(pArrayListEmployee != NULL){
        dataFile = fopen(path, "rb");

        if(dataFile != NULL){

            if(parser_EmployeeFromBinary(dataFile, pArrayListEmployee) == 1){
                retorno = 1;
            }
        fclose(dataFile);
        }
    }
    return retorno;
}



int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* employee;
    int retorno = 0;

    system("cls");

    if(pArrayListEmployee != NULL){
        printf("ID         NOMBRE     HORAS TRABAJADAS     SUELDO\n");
        for(int i= 0; i < ll_len(pArrayListEmployee); i++){

            employee = ll_get(pArrayListEmployee, i);

            if(employee != NULL){
                employee_list(employee);
                retorno = 1;
            }
        }
    }
    return retorno;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* employee;
    Employee* auxEmployee;
    int id;
    int retorno = 0;

    system("cls");

    if(pArrayListEmployee != NULL){
        auxEmployee = ll_get(pArrayListEmployee, (ll_len(pArrayListEmployee) - 1));

        employee_getId(auxEmployee, &id);

        if(pArrayListEmployee != NULL){
            employee = employee_add(id + 1);
            if(employee != NULL){
                ll_add(pArrayListEmployee, employee);
                retorno = 1;
            }
        }
    }
    return retorno;
}

int findIndex(LinkedList* employees, int id){

    Employee* employee;
    int auxId;
    int indice = -1;


    for(int i=0; i < ll_len(employees); i++){
        employee = ll_get(employees, i);
        employee_getId(employee, &auxId);

        if(id == auxId){
            indice = i;
            break;
        }
    }

    return indice;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    char nombre[128];
    int horasTrabajadas;
    int id;
    int sueldo;
    int opcion;
    int retorno = 0;
    int indice;
    Employee* employee;

    system("cls");

    if(pArrayListEmployee != NULL){
        controller_ListEmployee(pArrayListEmployee);
        utn_getNumeroEntero(&id, "Ingrese el id del empleado que desea modificar: ", " Error.", 0,9999, 5);
        indice = findIndex(pArrayListEmployee, id);
        employee = ll_get(pArrayListEmployee, indice);

        if(employee != NULL){
            employee_getNombre(employee, nombre);
            employee_getSueldo(employee, &sueldo);
            employee_getHorasTrabajadas(employee, &horasTrabajadas);

            printf("\n¿Que desea modificar?\n");
            printf("1. Nombre: %s\n", nombre);
            printf("2. Horas trabajadas: %d\n", horasTrabajadas );
            printf("3. Sueldo: %d\n", sueldo);

            if(utn_getNumeroEntero(&opcion, "Elija una opcion: ","Error. ", 1, 3, 10) == 0){
                switch(opcion){
                    case 1:
                        if(utn_getString(nombre, "Ingrese el nuevo nombre: ", "Error. ", 5)==0){
                            employee_setNombre(employee, nombre);
                            retorno = 1;
                        }
                        break;
                    case 2:
                        if(utn_getNumeroEntero(&horasTrabajadas, "Ingrese la cantidad de horas trabajadas: ", "Error. ",1,600, 5)==0){
                            employee_setHorasTrabajadas(employee, horasTrabajadas);
                            retorno = 1;
                        }
                        break;
                    case 3:
                        if(utn_getNumeroEntero(&sueldo, "Ingrese el nuevo sueldo: ", "Error. ",1,999999, 5)==0){
                            employee_setSueldo(employee, sueldo);
                            retorno = 1;
                        }
                        break;

                }

            }


        }
    }

    return retorno;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int index;
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    char respuesta;
    Employee* employee;

    system("cls");

    if(pArrayListEmployee != NULL){
        controller_ListEmployee(pArrayListEmployee);
        utn_getNumeroEntero(&id, "Ingrese el id del empleado que desea dar de baja: ", " Error.", 0,9999, 5);
        index = findIndex(pArrayListEmployee, id);

        if(index >= -1){
            employee = ll_get(pArrayListEmployee, index);
            employee_getNombre(employee, nombre);
            employee_getSueldo(employee, &sueldo);
            employee_getHorasTrabajadas(employee, &horasTrabajadas);

            printf("Id: %d\n", id);
            printf("Nombre: %s\n", nombre);
            printf("Sueldo: %d\n", sueldo );
            printf("Horas trabajdas: %d\n", horasTrabajadas);

            utn_getCharacter(&respuesta, "Seguro que desea dar de baja este empleado? s/n: ", "Error. ",'s', 'n', 5);
            if(respuesta == 's'){
                if(ll_remove(pArrayListEmployee, index) == 0){
                    retorno = 1;
                }
            }
        }
    }

    return retorno;
}

int sortNombres (void* employee1, void* employee2){

    int retorno;
    char nombre1[128];
    char nombre2[128];

    if(employee_getNombre(employee1, nombre1) && employee_getNombre(employee2, nombre2)){
        if(strcmp(nombre1, nombre2) == 1){
            retorno = 1;
        }else if(strcmp(nombre1, nombre2) == -1){
            retorno = -1;
        }else{
            retorno = 0;
        }
    }

    return retorno;

}

int sortId (void* employee1, void* employee2){

    int retorno;
    int id1;
    int id2;

    if(employee_getId(employee1, &id1) && employee_getId(employee2, &id2)){
        if(id1 > id2){
            retorno = 1;
        }else if(id1 < id2){
            retorno = -1;
        }else{
            retorno = 0;
        }
    }

    return retorno;
}

int sortHorasTrabajadas (void* employee1, void* employee2){

    int retorno;
    int horasTrabajadas1;
    int horasTrabajadas2;

    if(employee_getHorasTrabajadas(employee1, &horasTrabajadas1) && employee_getId(employee2, &horasTrabajadas2)){
        if(horasTrabajadas1 > horasTrabajadas2){
            retorno = 1;
        }else if(horasTrabajadas1 < horasTrabajadas2){
            retorno = -1;
        }else{
            retorno = 0;
        }
    }

    return retorno;
}

int sortSueldo (void* employee1, void* employee2){

    int retorno;
    int sueldo1;
    int sueldo2;

    if(employee_getSueldo(employee1, &sueldo1) && employee_getSueldo(employee2, &sueldo2)){
        if(sueldo1 > sueldo2){
            retorno = 1;
        }else if(sueldo1 < sueldo2){
            retorno = -1;
        }else{
            retorno = 0;
        }
    }

    return retorno;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcionCriterio;
    int opcionAscDesc;
    int retorno = 0;

    system("cls");
    if(pArrayListEmployee != NULL){
        printf("***Ordenar Empleados***\n");
        printf("Elija el criterio por el cual quiere ordenar\n");
        printf("1.Id\n");
        printf("2.Nombre\n");
        printf("3.Horas trabajadas\n");
        printf("4.Sueldo\n");
        utn_getNumeroEntero(&opcionCriterio, "Elija una opcion: ", "Error. ", 1, 4, 5);

        printf("Elija si quiere hacerlo de manera ascendiente o descendiente\n");
        printf("1.Descendente\n");
        printf("2.Ascendente\n");
        utn_getNumeroEntero(&opcionAscDesc, "Elija una opcion: ", "Error. ", 1, 2, 5);

        if(opcionCriterio == 1){
            ll_sort(pArrayListEmployee, sortId, opcionAscDesc - 1);
            retorno = 1;
        }else if(opcionCriterio == 2){
            ll_sort(pArrayListEmployee, sortNombres, opcionAscDesc - 1);
            retorno = 1;
        }else if(opcionCriterio == 3){
           ll_sort(pArrayListEmployee, sortHorasTrabajadas, opcionAscDesc - 1);
            retorno = 1;
        }else if(opcionCriterio == 4){
            ll_sort(pArrayListEmployee, sortSueldo, opcionAscDesc - 1);
            retorno = 1;
        }
    }

    return retorno;
}

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* file;
    Employee* employee;
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    int retorno = 0;


    if(pArrayListEmployee != NULL){
        file = fopen(path, "w");
        if(file != NULL){
            for(int i = 0; i< ll_len(pArrayListEmployee); i++){
                employee = ll_get(pArrayListEmployee, i);

                employee_getId(employee, &id);
                employee_getNombre(employee, nombre);
                employee_getHorasTrabajadas(employee, &horasTrabajadas);
                employee_getSueldo(employee, &sueldo);

                fprintf(file,"%d,%s,%d,%d\n", id, nombre, horasTrabajadas, sueldo);
            }
            retorno = 1;
        }
        fclose(file);
    }
    return retorno;
}


int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    FILE* file;
    int size;
    Employee* employee;


    if(pArrayListEmployee != NULL){
        file = fopen(path, "wb");
        size = ll_len(pArrayListEmployee);
        if(file != NULL){
            for(int i = 0; i< size; i++){
                employee = ll_get(pArrayListEmployee, i);
                if(employee != NULL){
                    fwrite(employee,sizeof(Employee),1,file);
                    retorno = 1;
                }

            }
        }
    }

    fclose(file);

    return retorno;
}

