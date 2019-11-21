/**
# Created By: Anonymous Noman
# Created On: 11/16/2019; 10:14 PM
*/
#ifndef OFFICIAL_NODE_H
#define OFFICIAL_NODE_H

#include <stdInclude.h>

typedef struct Node {
	void *data;
	struct Node *parent;
	size_t degree;
	struct Node **children;
	int depth;
	
	int (*compare)(void *thisData, void *data);
	
	int (*print)(void *data);
} Node;

Node *node_init(void *data, Node *parent);

Node *node_addChild(Node *node, void *data);

Node **node_addChildren(Node *node, size_t noOfChild, ...);

void node_free(Node *node);

#endif //OFFICIAL_NODE_H
