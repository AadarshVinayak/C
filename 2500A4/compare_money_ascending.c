#import <stdlib.h>

int compare_money_ascending (const void * element1, const void *element2){
	if(*(int*)element1->salary < *(int*)element2->salary){
		return(1);
	} else {
		return(0);
	}
}