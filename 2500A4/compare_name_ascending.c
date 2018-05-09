#import <stdlib.h>



int compare_name_ascending (const void * element1, const void *element2){
	if(strcmp(*(char*)element1->last_name,*(char*)element2->last_name)<0){
		return(1);
	} else {
		return(0);
	}
}