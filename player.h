
/** 
 * @brief It defines a space
 * 
 * @file space.h
 * @author Profesores PPROG
 * @version 1.0 
 * @date 13-01-2015
 * @copyright GNU Public License
 */

#ifndef PLAYER_H       					 /* Primero incluimos la estructura de nuestro archivo de cabezera y nuestros respectivos archivos de encabezamiento */ 
#define PLAYER_H
#include "types.h"
#include "game.h"

typedef struct _Player Player;


Player* player_create(Id id);
STATUS player_destroy(Player *player);
STATUS player_set_name(Player* player, char* name);
STATUS player_set_object(Player* player, BOOL value);
const char * player_get_name(Player* player);
Id player_get_id(Player* player);
BOOL player_get_object(Player* player);
int player_get_space(Player *player);
STATUS player_print(Player* player);

