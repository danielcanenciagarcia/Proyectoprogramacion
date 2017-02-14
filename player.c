#include <stdio.h>   
#include <stdlib.h>
#include <string.h>
#include "player.h"


struct _Player{

	Id id;
	char name[WORD_SIZE + 1];
	BOOL object;
	Id casilla;

};


Player* player_create(Id id){

	Player *newPlayer = NULL;
	
	if(id==NO_ID)
		return NULL;
		
	newPlayer = (Player *) malloc(sizeof(Player));
	
	if(newPlayer==NULL)
		return NULL;
		
	newPlayer->id = id;
	newPlayer->name[0] = '\0';
	newPlayer->object = FALSE;
	newPlayer->space = 0;


	return newPlayer;


}

STATUS player_destroy(Player *player){


	if(!player)
		return ERROR;
	
	free(player);
	
	player = NULL;
	
	return OK;

}

STATUS player_set_name(Player* player, char* name){

	if (!player || !name)
        return ERROR;
    

    if (!strcpy(player->name, name)
        return ERROR;
    

	return OK;


}

STATUS player_set_object(Player* player, BOOL value) {  
    
    if (!player) 
        return ERROR;
        
    player->object = value;
    
    return OK;
}

const char * player_get_name(Player* player) {           
	
    if (!player) 
        return NULL;
    
    return player->name;
}

Id player_get_id(Player* player) {        				  

    if (!space) 
        return NO_ID;
    
    return space->id;
}


BOOL player_get_object(Player* player) { 				 

    if (!player) 
        return FALSE;
    
    return player->object;
}

Id player_get_casilla(Player *player){
	
     if(!player)
        return NO_ID;
	
    return player->casilla;
	
	
} 

STATUS player_print(Player* player) {					   
														
    Id idaux = NO_ID;
  
    if (!player) 
        return ERROR;
    

    fprintf(stdout, "--> Player (Id: %ld; Name: %s)\n", player->id, player->name);   
    
    
    idaux = player_get_casilla(player);
    if (!idaux) {
        fprintf(stdout, "--->Casilla: %ld\n", idaux);
    } 
    
    if (player_get_object(player)) {
        fprintf(stdout, "---> Object in the space.\n");
    } else {
        fprintf(stdout, "---> No object in the space.\n");
    }

    return OK;
}


