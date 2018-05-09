#import <stdlib.h>



int compare_id_ascending (const void * element1, const void *element2){
	if(*(int*)element1->id_number < *(int*)element2->id_number){
		return(1);
	} else {
		return(0);
	}
}