/* fileName: list.h
 * Author: Josh Herman
 * description: this is a header file for list.c, it includes the structure used and the function(s) used
 */


#ifndef LIST
#define LIST

#include "node.h"

typedef struct list_t {

	node_t* headPtr;
	node_t* tailPtr;

}list_t;

void createList(list_t* listPtr);
void insertNode(list_t* listPtr, node_t* nodePtr);
void deleteList(list_t* listPtr);

#endif
