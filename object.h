/** 
 * @brief It defines a space
 * 
 * @file space.h
 * @author Profesores PPROG
 * @version 1.0 
 * @date 13-01-2015
 * @copyright GNU Public License
 */

#ifndef OBJECT_H       					 
#define OBJECT_H
#include "types.h"
#include "game.h"

typedef struct _Object Object;

Object* object_create(Id id);
STATUS object_destroy(Object* object);
STATUS object_set_name(Object* object, char* name);
const char * object_get_name(Object* object);
STATUS object_print(Object* object);
