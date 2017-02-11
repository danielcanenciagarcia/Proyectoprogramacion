/** 
 * @brief It implements the game interface and all the associated callbacks
 * for each command
 * 
 * @file game.c
 * @author Profesores PPROG
 * @version 1.0 
 * @date 13-01-2015 
 * @copyright GNU Public License
 */

#include <stdio.h>														/*Primero incluimos las librerias estandar,nuestros respectivos archivos de encabezamiento y las macros necesarias*/
#include <stdlib.h>
#include <string.h>
#include "game.h"

#define N_CALLBACK 4


/**
   Define the function type for the callbacks
*/
typedef void (*callback_fn)(Game* game);


/**
   List of callbacks for each command in the game 
*/
void game_callback_unknown(Game* game);
void game_callback_quit(Game* game);
void game_callback_next(Game* game);
void game_callback_back(Game* game);

static callback_fn game_callback_fn_list[N_CALLBACK]={					/* Variable estática */
  game_callback_unknown,
  game_callback_quit,
  game_callback_next,
  game_callback_back
  };


/**
   Private functions
*/

STATUS game_load_spaces(Game* game, char* filename);			
STATUS game_add_space(Game* game, Space* space);
Id     game_get_space_id_at(Game* game, int position);
STATUS game_set_player_location(Game* game, Id id);
STATUS game_set_object_location(Game* game, Id id);


/**
   Game interface implementation
 */

STATUS game_create(Game* game) {										/*  Esta función,tipo STATUS, recibe como argumentos una variable de tipo Game* y tras inicializar cada uno de los elementos de
																			la variable game->spaces asigna valores a diferentes punteros a variables. Devuelve OK si se completa con exito*/
	
  int i;
  
  for (i = 0; i < MAX_SPACES; i++) {
    game->spaces[i] = NULL;
  }
  
  game->player_location = NO_ID;
  game->object_location = NO_ID;
  game->last_cmd = NO_CMD;
  
  return OK;
}

STATUS game_create_from_file(Game* game, char* filename) {		        /*  Función tipo STATUS, recibe una variable tipo Game* y otra tipo char*, si por algún motivo falla la creación del juego o
																			la carga de espacios esta devuelve ERROR. Además situará las posiciones del jugador y del objeto iniciales(0)*/

  if (game_create(game) == ERROR)
    return ERROR;

  if (game_load_spaces(game, filename) == ERROR)
    return ERROR;

  game_set_player_location(game, game_get_space_id_at(game, 0));
  game_set_object_location(game, game_get_space_id_at(game, 0));

  return OK;
}

STATUS game_destroy(Game* game) {										/*  Función tipo STATUS, recibe una variable tipo Game* y usará la función space_destroy para finalizar el juego  */
	
    int i = 0;

    for (i = 0; (i < MAX_SPACES) && (game->spaces[i] != NULL); i++) {
      space_destroy(game->spaces[i]);
    }
        
    return OK;
}

STATUS game_add_space(Game* game, Space* space) {						/* El cometido de esta función es añadir un espacio, siempre y cuando estos existan y no se sobrepase el numero máximo de 
																		   los mismos. Recibe dos variable, tipo Game* y Space*.Devuelve OK si todo se ha realizado con exito. Si por el contario algo 
																		   falla devolverá ERROR */
			
    int i = 0;

    if (space == NULL) {
        return ERROR;
    }

    while ( (i < MAX_SPACES) && (game->spaces[i] != NULL)){
        i++;
    }

    if (i >= MAX_SPACES) {
        return ERROR;
    }

    game->spaces[i] = space;

    return OK;
}

Id game_get_space_id_at(Game* game, int position) {						/* Función tipo Id, recibe dos argumentos tipo Game* e int y devuelve la identificación de la posición en la que se encuentra.
																		   Si se sobrepasa el maximo de espacios o si este es negativo, devolverá -1(NO_ID). */

    if (position < 0 || position >= MAX_SPACES) {
        return NO_ID;
    }

    return space_get_id(game->spaces[position]);
}

Space* game_get_space(Game* game, Id id) {								/* Función tipo Space*, recibe dos argumentos tipo Game* y Id     */
	
    int i = 0;

    if (id == NO_ID) {
      return NULL;
    }
    
    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
      if (id == space_get_id(game->spaces[i])){
      	return game->spaces[i];
      }
    }
    
    return NULL;
}

STATUS game_set_player_location(Game* game, Id id) {					/* */
    
    if (id == NO_ID) {
        return ERROR;
    }

    game->player_location = id;

}

STATUS game_set_object_location(Game* game, Id id) {					/* */
  
    int i = 0;

    if (id == NO_ID) {
        return ERROR;
    }

    game->object_location = id;

    return OK;
}
	
Id game_get_player_location(Game* game) {								/* */
    return game->player_location;
}

Id game_get_object_location(Game* game) {								/* */
    return game->object_location;
}

STATUS game_update(Game* game, T_Command cmd) {							/* */
	
  game->last_cmd = cmd;
  (*game_callback_fn_list[cmd])(game);
  return OK;
  
}

T_Command game_get_last_command(Game* game){							/* */
	
  return game->last_cmd;
}

void game_print_data(Game* game) {										/* */
		
  int i = 0;
  
  printf("\n\n-------------\n\n");
  
  printf("=> Spaces: \n");
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    space_print(game->spaces[i]);
  }
  
  printf("=> Object location: %d\n", (int) game->object_location);    
  printf("=> Player location: %d\n", (int) game->player_location);
  printf("prompt:> ");
}

BOOL game_is_over(Game* game) {											/* */
  return FALSE;
}

/**
   Callbacks implementation for each action 
*/

void game_callback_unknown(Game* game) {
}

void game_callback_quit(Game* game) {
}


void game_callback_next(Game* game) {									/* */
	
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;
  
  space_id = game_get_player_location(game);
  if (space_id == NO_ID) {
    return;
  }
  
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      current_id = space_get_south(game->spaces[i]);
      if (current_id != NO_ID) {
		game_set_player_location(game, current_id);
      }
      return;
    }
  }
}

void game_callback_back(Game* game) {									/* */
	
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;
  
  space_id = game_get_player_location(game);
  
  if (NO_ID == space_id) {
    return;
  }
  
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      current_id = space_get_north(game->spaces[i]);
      if (current_id != NO_ID) {
		game_set_player_location(game, current_id);
      }
      return;
    }
  }
}


