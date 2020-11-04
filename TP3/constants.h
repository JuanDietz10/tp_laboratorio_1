/*
 * constants.h
 *
 *  Created on: 29 oct. 2020
 *      Author: Juan Dietz
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#define LENNOMBRE 21

#define HORASMIN  0
#define HORASMAX  500

#define SUELDOMIN 0
#define SUELDOMAX 1500000

#define OPCMIN  1
#define OPCMAX  5

#define OPCPMIN 0
#define OPCPMAX 9

#define RETRIES 3

#define MSG_INGRESE_OPC     "Ingrese opcion"
#define MSG_INGRESE_ID      "Ingrese el ID"
#define MSG_INGRESE_NOMBRE  "Ingrese el nombre"
#define MSG_INGRESE_HORAS   "Ingrese las horas trabajadas"
#define MSG_INGRESE_SUELDO  "Ingrese el sueldo"

#define MSG_ERROR_OPC       "Error al ingresar la opcion"
#define MSG_ERROR_ID        "Error al ingresar el ID"
#define MSG_ERROR_NOMBRE    "Error al ingresar el nombre"
#define MSG_ERROR_HORAS     "Error al ingresar las horas"
#define MSG_ERROR_SUELDO    "Error al ingresar el sueldo"

#define MSG_LIST            "Lista cargada"
#define MSG_ADD             "Empleado agregado"
#define MSG_EDIT            "Empleado modificado"
#define MSG_REM             "Empleado eliminado"
#define MSG_SORT            "Lista ordenada"
#define MSG_SAVE            "Archivo guardado"

#define MSG_ERROR_LOAD      "Error al cargar la lista"
#define MSG_ERROR_ADD       "Error al agregar empleado a la lista"
#define MSG_ERROR_LIST      "Error al listar"
#define MSG_ERROR_EDIT      "Error el ID que intenta modificar no existe o ha sido eliminado"
#define MSG_ERROR_REM       "Error al ID que intenta eliminar no existe o ha sido eliminado"
#define MSG_ERROR_SORT      "Error al ordenar"
#define MSG_ERROR_SAVE      "Error al guardar el archivo"

#define PATH_CSV "data.csv"
#define PATH_BIN "data.bin"
#define PATH_ID  "id.conf"

void menuModificar(void);
void menuPrincipal(void);
void menuOrdenar  (void);

#endif /* CONSTANTS_H_ */
