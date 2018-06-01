/* filename: list.c
 * Author: Josh Herman
 * description: this file is the .c file for list.h, it executes the functions that were labeled there, and it uses that struct
 */

#include "list.h"

#include <stdlib.h>
#include <stdio.h>

/* createList: this function intiaties a doubly linked list
 * parameters: listPtr = a pointer to the list being intiated
 * PostCondition: the head and tail pointers of this list now point to NULL
 */

void createList(list_t* listPtr){
	listPtr -> headPtr = NULL;
	listPtr -> tailPtr = NULL;

}

/* insertNode: this fucntion inserts a node in the list AT THE BEGINNING OF THE FILE
 * parameters:
 *     listPtr: the pointer to the list in question
 *     nodePtr: a pointer to the node being inserted
 * PreConidtion: the node is intiated correctly, this could really screw up list if not
 * PostCondition: the list now has this node added at the beginning
 */

void insertNode(list_t* listPtr, node_t* nodePtr){
	if(listPtr -> headPtr == NULL && listPtr -> tailPtr == NULL){ //if list is empty
		listPtr -> headPtr = nodePtr;
		listPtr -> tailPtr = nodePtr;
	}
	else { //list not empty, put new node at beginning
		nodePtr -> nextPtr = listPtr -> headPtr;
		listPtr -> headPtr -> previousPtr = nodePtr;
		listPtr -> headPtr = nodePtr;
	}
}

/* deleteList: this function will delete the ENTIRE list passed to it
 * parameters:
 *     listPtr: a pointer to the list being deleted
 * PostCondition: head and tail pointers are set to NULL, and EVERY node in list is deleted
 */

void deleteList(list_t* listPtr){
	node_t* tempPtr = listPtr -> headPtr;

	while(listPtr -> headPtr != NULL){ //while list is not empty
		listPtr -> headPtr = listPtr -> headPtr -> nextPtr; //make headPtr = to the next node in the list
		free(tempPtr);
		tempPtr = listPtr -> headPtr;
	}

	listPtr -> tailPtr = NULL;
}
