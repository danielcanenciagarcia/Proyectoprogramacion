
#include <stdlib.h>
#include <stdio.h>
#include "object.h"


struct _Object{
	
	Id id;
	char  name[WORD_SIZE + 1];
	
	
};

Object* object_create(Id id){
	
	Object* newObject=NULL;
	
	if(id=NO_ID)
		return NULL;
		
	newObject = (Object *) malloc(sizeof (Object));
	
	if(!newObject)
		return NULL;
		
	newObject->id = id;
	newObject->name[0] = '\0';
	
	return newObject;
	
}

STATUS object_destroy(Object* object){
	
	if(!object)
		return ERROR;
	
	free(object);
	
	object = NULL;
	
	return OK;
	
}


STATUS object_set_name(Object* object, char* name){
	
	if (!object || !name)
        return ERROR;
    

    if (!strcpy(object->name, name))
        return ERROR;
    

    return OK;
	
}


const char * object_get_name(Object* object){
	
	if(!object) 
        return NULL;
    
    return object->name;
	
}
	
STATUS object_print(Object* object) {					 
    
    Id idaux = NO_ID;
  
    if (!object) 
        return ERROR;
    

    fprintf(stdout, "--> Space (Id: %ld; Name: %s)\n", object->id, object->name);   
    
    
    return OK;
}






	
	
