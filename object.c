

#include <stdlib.h>
#include <stdio.h>
#include "object.h"


struct _Object{
	
	Id id;
	Id back;
	Id next;
	BOOL player;
	
};

Object* object_create(Id id){
	
	Object* newObject=NULL;
	
	if(id=NO_ID)
		return NULL;
		
	newObject = (Object *) malloc(sizeof (Object));
	
	if(!newObject)
		return NULL;
		
	newObject->id = id;
	newObject->back;
	newObject->next;
	newObject->player;
	
	return newObject;
	
}

STATUS object_destroy(Object* object){
	
	if(!object)
		return ERROR;
	
	free(object);
	
	object = NULL;
	
	return OK;
	
}


STATUS object_set_next(Object* object, Id id){
	
	
}

STATUS object_set_back(Object* object, Id id){
	
	
}

STATUS object_get_next(Object* object){
	
	
}

STATUS object_get_back(Object* object){
	
	
}


STATUS object_print(Object* object){
	
	
	
}

	
	
	
	
