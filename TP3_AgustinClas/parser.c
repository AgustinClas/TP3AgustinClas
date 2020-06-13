#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "UTN.h"


int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int cant;
    char buffer[4][128];
    Employee* auxEmployee;
    char respuesta;

    if(pArrayListEmployee != NULL){

        if(!ll_isEmpty(pArrayListEmployee)){
            utn_getCharacter(&respuesta, "Desea sobreescribir los datos cargados en el sistema? s/n: ", "Error. ", 's', 'n', 5);        }

        if(respuesta == 's' || ll_isEmpty(pArrayListEmployee)){
            ll_clear(pArrayListEmployee);
            while(!feof(pFile)){

                cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
                if (cant == 4){
                    //Con la linea de abajo podemos hacer que muestre cada empleado a medida que los va cargando
                    //printf("%s,%s,%s,%s\n", buffer[0], buffer[1], buffer[2], buffer[3]);
                    auxEmployee = employee_newParametrosStr (buffer[0], buffer[1], buffer[2], buffer[3]);
                    ll_add(pArrayListEmployee, auxEmployee);
                    retorno = 1;
                }else{
                    retorno = 0;
                    printf("%s %s %s %s", buffer[0], buffer[1], buffer[2], buffer[3]);
                    break;
                }
            }
        }
    }
    return retorno;
}


int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int read;
    Employee* auxEmployee;
    char respuesta;

    if(pArrayListEmployee != NULL && pFile != NULL){

        if(!ll_isEmpty(pArrayListEmployee)){
            utn_getCharacter(&respuesta, "Desea sobreescribir los datos cargados en el sistema? s/n: ", "Error. ", 's', 'n', 5);
        }

        if(respuesta == 's' || ll_isEmpty(pArrayListEmployee)){

            ll_clear(pArrayListEmployee);
            while(!feof(pFile)){
                auxEmployee = employee_new();
                read = fread(auxEmployee,sizeof(Employee),1,pFile);
                if (read == 1){
                    ll_add(pArrayListEmployee, auxEmployee);
                    retorno = 1;
                }

            }
        }
    }
    return retorno;
}

