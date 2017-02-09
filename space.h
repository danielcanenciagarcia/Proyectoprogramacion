/** 
 * @brief It defines a space
 * 
 * @file space.h
 * @author Profesores PPROG
 * @version 1.0 
 * @date 13-01-2015
 * @copyright GNU Public License
 */

#ifndef SPACE_H       /* Primero incluimos la estructura de nuestro archivo de cabezera y nuestros respectivos archivos de encabezamiento */ 
#define SPACE_H
#include "types.h"

typedef struct _Space Space;     /* Dejamos constancia de una estructura tipo Space así como la declaración de las macros necesarias */

#define MAX_SPACES 100
#define FIRST_SPACE 1

Space* space_create(Id id);				/* Es necesario tomar constancia de las funciones utilizadas posteriormente en nuestro archivo de implementación(.c) */
STATUS space_destroy(Space* space);
Id space_get_id(Space* space);
STATUS space_set_name(Space* space, char* name);
const char* space_get_name(Space* space);
STATUS space_set_north(Space* space, Id id);
Id space_get_north(Space* space);
STATUS space_set_south(Space* space, Id id);
Id space_get_south(Space* space);
STATUS space_set_east(Space* space, Id id);
Id space_get_east(Space* space);
STATUS space_set_west(Space* space, Id id);
Id space_get_west(Space* space);
STATUS space_set_object(Space* space, BOOL value);
BOOL space_get_object(Space* space);
STATUS space_print(Space* space);

#endif
