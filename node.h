/* filename: node.h
 * Author: Josh Herman
 * description: this is the header file to node.c, it contains the structure used and the function(s) used.
 */


#ifndef NODE_H
#define NODE_H

#include "SurveyEntry.h"

typedef struct node_t{
	SurveyEntry data;
	struct node_t* nextPtr;
	struct node_t* previousPtr;
}node_t;

node_t* initNode(SurveyEntry);

#endif
