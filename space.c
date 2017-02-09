#include <stdio.h>      /*Primero incluimos las librerias estandar y nuestros respectivos archivos de encabezamiento*/
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "space.h"

struct _Space {					/* Estructura tipo Space compuesta por distintos tipos de variables */ 
    Id id;
    char name[WORD_SIZE + 1];
    Id north;
    Id south;
    Id east;
    Id west;
    BOOL object;
};
 
Space* space_create(Id id) {             /* Función que recibe una variable tipo Id y devuelve otra tipo newSpace */
 
    Space *newSpace = NULL;

    if (id == NO_ID)                      /* Se realizan las comprbaciones de errores pertinentes(id) y se reserva memoria dinámica para dicha variable */
        return NULL;

    newSpace = (Space *) malloc(sizeof (Space));   

    if (newSpace == NULL)             /* Comprobación de error tras haber reservado memoria */
        return NULL;
    
    
    newSpace->id = id;                /* Declaración e inicialización de distinto tipo de variables */
    newSpace->name[0] = '\0';
    newSpace->north = NO_ID;
    newSpace->south = NO_ID;
    newSpace->east = NO_ID;
    newSpace->west = NO_ID;
    newSpace->object = FALSE;

    return newSpace;
}

STATUS space_destroy(Space* space) {     /* Función tipo STATUS encargada de liberar memoria para una variable determinada, devuelve ERROR si hay algún error e inicializa la variable final*/
    
    if (!space) 
        return ERROR;
    
    free(space);
    
    space = NULL;

    return OK;
}

STATUS space_set_name(Space* space, char* name) {   /* Función tipo STATUS, devuelve OK si las operaciones se han completado satisfactoriamente y ERROR si se ha producido algun fallo */
	
    if (!space || !name)
        return ERROR;
    

    if (!strcpy(space->name, name)
        return ERROR;
    

    return OK;
}

STATUS space_set_north(Space* space, Id id) {      /* Función tipo STATUS, recibe una variable tipo Space* y otra tipo Id con el propósito de orientar el espacio en dirección norte */
    
    if (!space || id == NO_ID) 
        return ERROR;
    
    space->north = id;
    
    return OK;
}

STATUS space_set_south(Space* space, Id id) {	   /* Función tipo STATUS, recibe una variable tipo Space* y otra tipo Id con el proposito de orientar el espacio en dirección sur */
    
    if (!space || id == NO_ID) 
        return ERROR;
    
    space->south = id;
    return OK;
}

STATUS space_set_east(Space* space, Id id) {	   /* Función tipo STATUS, recibe una variable tipo Space* y otra tipo Id con el propósito de orientar el espacio en dirección este */
    if (!space || id == NO_ID) 
        return ERROR;
    
    space->east = id;
    return OK;
}

STATUS space_set_west(Space* space, Id id) {	   /* Función tipo STATUS, recibe una variable tipo Space* y otra tipo Id con el propósito de orientar el espacio en dirección oeste */
    
    if (!space || id == NO_ID) 
        return ERROR;
    
    space->west = id;
    return OK;
}

STATUS space_set_object(Space* space, BOOL value) {   /* Función tipo STATUS, recibe un variable tipo Space* y otra tipo BOOL(true,false) con el propósito de asignar ese valor a nuestro objeto */
    
    if (!space) 
        return ERROR;
        
    space->object = value;
    
    return OK;
}

const char * space_get_name(Space* space) {           /* Función tipo const char*, recibe un variable tipo Space* y devuelve el nombre de un espacio existente */

    if (!space) 
        return NULL;
    
    return space->name;
}

Id space_get_id(Space* space) {        				  /* Función tipo Id, recibe una variable tipo Space* y devuelve la identificación del mismo */

    if (!space) 
        return NO_ID;
    
    return space->id;
}

Id space_get_north(Space* space) {				      /* Función tipo Id, recibe una variable Space* y devuelve la identificación norte */

    if (!space) 
        return NO_ID;
    
    return space->north;
}

Id space_get_south(Space* space) {					  /* Función tipo Id, recibe una variable Space* y devuelve la identificación sur */
    
    if (!space) 
        return NO_ID;
    
    return space->south;
}

Id space_get_east(Space* space) {					  /* Función tipo Id, recibe una variable Space* y devuelve la identificación este */

    if (!space) 
        return NO_ID;
    
    return space->east;
}

Id space_get_west(Space* space) {					  /* Función tipo Id, recibe una variable Space* y devuelve la identificación oeste */

    if (!space) 
        return NO_ID;
    
    return space->west;
}

BOOL space_get_object(Space* space) { 				  /* Función tipo BOOL, recibe una variable Space* y devuelve el valor del objeto(en este caso tipo BOOL(1 ó 0) */

    if (!space) 
        return FALSE;
    
    return space->object;
}

STATUS space_print(Space* space) {					  /* Función tipo STATUS, recibe una variable tipo Space* y devuelve Ok si su objetivo se ha completado con exito, si existe algún fallo devolverá ERROR. 
														 Su objetivo será devolver la orientación del espacio y el valor del objeto */
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

