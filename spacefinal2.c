
/*Primero incluimos las librerias estandar y nuestros respectivos archivos de encabezamiento*/

#include <stdio.h>      
#include <stdlib.h>
#include <string.h>
#include "space.h"

/* Estructura tipo Space compuesta por distintos tipos de variables */ 

struct _Space {					
    Id id;
    char name[WORD_SIZE + 1];
    Id north;
    Id south;
    Id east;
    Id west;
    BOOL object;
};

/* Función que recibe una variable tipo Id y devuelve otra tipo newSpace */
 
Space* space_create(Id id) {             
 
    Space *newSpace = NULL;

    /* Se realizan las comprbaciones de errores pertinentes(id) y se reserva memoria dinámica para dicha variable */

    if (id == NO_ID)                      
        return NULL;

    newSpace = (Space *) malloc(sizeof (Space));   

    /* Comprobación de error tras haber reservado memoria */

    if (newSpace == NULL)             
        return NULL;
    
    /* Declaración e inicialización de distinto tipo de variables */
    
    newSpace->id = id;                
    newSpace->name[0] = '\0';
    newSpace->north = NO_ID;
    newSpace->south = NO_ID;
    newSpace->east = NO_ID;
    newSpace->west = NO_ID;
    newSpace->object = FALSE;

    return newSpace;
}

/* Función tipo STATUS encargada de liberar memoria para una variable determinada, devuelve ERROR si hay algún error
   e inicializa la variable final*/

STATUS space_destroy(Space* space) {     
    
    if (!space) 
        return ERROR;
    
    free(space);
    
    space = NULL;

    return OK;
}

 /* Función tipo STATUS, devuelve OK si las operaciones se han completado satisfactoriamente y ERROR si se ha producido algun fallo */

STATUS space_set_name(Space* space, char* name) {  
	
    if (!space || !name)
        return ERROR;
    

    if (!strcpy(space->name, name)
        return ERROR;
    

    return OK;
}

/* Función tipo STATUS, recibe una variable tipo Space* y otra tipo Id con el propósito de orientar el espacio en dirección norte */

STATUS space_set_north(Space* space, Id id) {      
    
    if (!space || id == NO_ID) 
        return ERROR;
    
    space->north = id;
    
    return OK;
}

/* Función tipo STATUS, recibe una variable tipo Space* y otra tipo Id con el proposito de orientar el espacio en dirección sur */

STATUS space_set_south(Space* space, Id id) {	   
    
    if (!space || id == NO_ID) 
        return ERROR;
    
    space->south = id;
    return OK;
}

/* Función tipo STATUS, recibe una variable tipo Space* y otra tipo Id con el propósito de orientar el espacio en dirección este */

STATUS space_set_east(Space* space, Id id) {	   
    if (!space || id == NO_ID) 
        return ERROR;
    
    space->east = id;
    return OK;
}

 /* Función tipo STATUS, recibe una variable tipo Space* y otra tipo Id con el propósito de orientar el espacio en dirección oeste */

STATUS space_set_west(Space* space, Id id) {	  
    
    if (!space || id == NO_ID) 
        return ERROR;
    
    space->west = id;
    return OK;
}

/* Función tipo STATUS, recibe un variable tipo Space* y otra tipo BOOL(true,false) con el propósito de asignar ese valor a nuestro objeto */

STATUS space_set_object(Space* space, BOOL value) {   
    
    if (!space) 
        return ERROR;
        
    space->object = value;
    
    return OK;
}

 /* Función tipo const char*, recibe un variable tipo Space* y devuelve el nombre de un espacio existente */

const char * space_get_name(Space* space) {          

    if (!space) 
        return NULL;
    
    return space->name;
}

/* Función tipo Id, recibe una variable tipo Space* y devuelve la identificación del mismo */

Id space_get_id(Space* space) {        				  

    if (!space) 
        return NO_ID;
    
    return space->id;
}

/* Función tipo Id, recibe una variable Space* y devuelve la identificación norte */

Id space_get_north(Space* space) {				      

    if (!space) 
        return NO_ID;
    
    return space->north;
}

 /* Función tipo Id, recibe una variable Space* y devuelve la identificación sur */

Id space_get_south(Space* space) {					
    
    if (!space) 
        return NO_ID;
    
    return space->south;
}

 /* Función tipo Id, recibe una variable Space* y devuelve la identificación este */

Id space_get_east(Space* space) {					 

    if (!space) 
        return NO_ID;
    
    return space->east;
}

/* Función tipo Id, recibe una variable Space* y devuelve la identificación oeste */

Id space_get_west(Space* space) {					  

    if (!space) 
        return NO_ID;
    
    return space->west;
}

/* Función tipo BOOL, recibe una variable Space* y devuelve el valor del objeto(en este caso tipo BOOL(1 ó 0) */

BOOL space_get_object(Space* space) { 				  

    if (!space) 
        return FALSE;
    
    return space->object;
}

/* Función tipo STATUS, recibe una variable tipo Space* y devuelve Ok si su objetivo se ha completado con exito, 
   si existe algún fallo devolverá ERROR. Su objetivo será devolver la orientación del espacio y el valor del objeto */

STATUS space_print(Space* space) {					  
	
    Id idaux = NO_ID;
  
    if (!space) 
        return ERROR;
    

    fprintf(stdout, "--> Space (Id: %ld; Name: %s)\n", space->id, space->name);   
    
    idaux = space_get_north(space);
    if (NO_ID != idaux) {
        fprintf(stdout, "---> North link: %ld.\n", idaux);
    } else {
        fprintf(stdout, "---> No north link.\n");
    }
    
    idaux = space_get_south(space);
    if (NO_ID != idaux) {
        fprintf(stdout, "---> South link: %ld.\n", idaux);
    } else {
        fprintf(stdout, "---> No south link.\n");
    }
    
    idaux = space_get_east(space);
    if (NO_ID != idaux) {
        fprintf(stdout, "---> East link: %ld.\n", idaux);
    } else {
        fprintf(stdout, "---> No east link.\n");
    }
    
    idaux = space_get_west(space);
    if (NO_ID != idaux) {
        fprintf(stdout, "---> West link: %ld.\n", idaux);
    } else {
        fprintf(stdout, "---> No west link.\n");
    }
    
   if (space_get_object(space)) {
        fprintf(stdout, "---> Object in the space.\n");
    } else {
        fprintf(stdout, "---> No object in the space.\n");
    }

    return OK;
}

