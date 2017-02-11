/** 
 * @brief It defines a space
 * 
 * @file space.h
 * @author Profesores PPROG
 * @version 1.0 
 * @date 13-01-2015
 * @copyright GNU Public License
 */

#ifndef OBJECT_H       					 /* Primero incluimos la estructura de nuestro archivo de cabezera y nuestros respectivos archivos de encabezamiento */ 
#define OBJECT_H
#include "types.h"

typedef struct _Object Object;

Object* object_create(Id id);
Object* object_destroy(Object* object);




