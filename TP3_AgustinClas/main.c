#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "UTN.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/
int menu(void);

int main()
{
    int option;

    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        option = menu();

        switch(option)
        {
            case 1:
                if(controller_loadFromText("data.csv", listaEmpleados) == 1){
                    printf("Empleados cargados correctamente!\n\n");
                }else{
                    printf("No se pudieron cargar los empleados\n\n");
                }
                break;
            case 2:
                if(controller_loadFromBinary("data.bin", listaEmpleados) == 1){
                    printf("Empleados cargados correctamente!\n\n");
                }else{
                    printf("No se pudieron cargar los empleados\n\n");
                }
                break;
            case 3:
                if(!ll_isEmpty(listaEmpleados)){
                    if(controller_addEmployee(listaEmpleados)){
                        printf("Empleado cargado correctamente\n\n");
                    }else{
                        printf("No se pudo cargar el empleado\n\n");
                    }
                }else{
                    printf("No hay ninguna lista de empleados en el sistema\n\n");
                }
                break;
            case 4:
                if(!ll_isEmpty(listaEmpleados)){
                    if(controller_editEmployee(listaEmpleados)){
                        printf("Empleado modificado correctamente\n\n");
                    }else{
                        printf("No se pudo modificar el empleado\n\n");
                    }
                }else{
                    printf("No hay ninguna lista de empleados en el sistema\n\n");
                }
                break;
            case 5:
                if(!ll_isEmpty(listaEmpleados)){
                    if(controller_removeEmployee(listaEmpleados)){
                        printf("Empleado dado de baja correctamente\n\n");
                    }else{
                        printf("No se pudo dar de baja el empleado\n\n");
                    }
                }else{
                    printf("No hay ninguna lista de empleados en el sistema\n\n");
                }
                break;
            case 6:
                if(!ll_isEmpty(listaEmpleados)){
                   controller_ListEmployee(listaEmpleados);
                }else{
                    printf("No hay ninguna lista de empleados en el sistema\n\n");
                }
                break;
            case 7:
                if(!ll_isEmpty(listaEmpleados)){
                    if(controller_sortEmployee(listaEmpleados)){
                        printf("Empleados ordenados correctamente\n\n");
                    }else{
                        printf("No se pudo ordenar a los empleados\n\n");
                    }
                }else{
                    printf("No hay ninguna lista de empleados en el sistema\n\n");
                }
                break;
            case 8:
                if(controller_saveAsText("data.csv", listaEmpleados) == 1){
                    system("cls");
                    printf("Empleados gurdados correctamente\n\n");
                }
                break;
            case 9:
                if(controller_saveAsBinary("data.bin", listaEmpleados) == 1){
                    system("cls");
                    printf("Empleados gurdados correctamente\n\n");
                }
                break;
        }
    }while(option != 10);

    ll_deleteLinkedList(listaEmpleados);
    return 0;
}

int menu(void){

    int opcion = 10;

    printf("Menu:\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
    printf("10. Salir\n");

    if(utn_getNumeroEntero(&opcion, "Ingrese una opcion: ", "Error. ", 1, 10, 10) == -1){
        printf("Supero la cantidad de reintentos permitida. Usted saldra del programa\n");
    }

    return opcion;

}
