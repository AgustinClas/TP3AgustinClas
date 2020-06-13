/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return 1 en caso de exito y 0 en caso de error
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return 1 en caso de exito y 0 en caso de error
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return 1 en caso de exito y 0 en caso de error
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);

/** \brief Modificar datos de empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return 1 en caso de exito y 0 en caso de error
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return 1 en caso de exito y 0 en caso de error
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return 1 en caso de exito y 0 en caso de error
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return 1 en caso de exito y 0 en caso de error
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return 1 en caso de exito y 0 en caso de error
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return 1 en caso de exito y 0 en caso de error
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief busca el indice de un empleado a traves de su id
 *
 * \param pArrayListEmployee LinkedList*
 * \param id
 * \return indice
 *
 */
int findIndex(LinkedList* employees, int id);

/** \brief ordena los empleados por su id
 *
 * \param puntero a empleado
 * \param puntero a empleado
 * \return 1 si el primer empleado es mayor, -1 si el segundo empleado es mayor, 0 si son iguales
 *
 */
int sortId (void* employee1, void* employee2);

/** \brief ordena los empleados por su nombre
 *
 * \param puntero a empleado
 * \param puntero a empleado
 * \return 1 si el primer empleado es mayor, -1 si el segundo empleado es mayor, 0 si son iguales
 *
 */
int sortNombres (void* employee1, void* employee2);

/** \brief ordena los empleados por sus horas trabajadas
 *
 * \param puntero a empleado
 * \param puntero a empleado
 * \return 1 si el primer empleado es mayor, -1 si el segundo empleado es mayor, 0 si son iguales
 *
 */
int sortHorasTrabajadas (void* employee1, void* employee2);

/** \brief ordena los empleados por su sueldo
 *
 * \param puntero a empleado
 * \param puntero a empleado
 * \return 1 si el primer empleado es mayor, -1 si el segundo empleado es mayor, 0 si son iguales
 *
 */
int sortSueldo (void* employee1, void* employee2);


