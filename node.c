/* fileName: node.c
 * Author: Josh Herman
 * description: this file contains the functions defined in node.h, and it will be used in other files within this project
 */


#include "node.h"
#include <stdlib.h>

node_t* initNode(SurveyEntry inputEntry){
	node_t* nodePtr = (node_t*) malloc(sizeof(node_t));

	nodePtr -> data = inputEntry;

	nodePtr -> nextPtr = NULL;
	nodePtr -> previousPtr = NULL;

	return nodePtr;
}
