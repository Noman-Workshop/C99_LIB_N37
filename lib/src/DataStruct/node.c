/**
# Created By: Anonymous Noman
# Created On: 11/16/2019; 10:15 PM
*/

#include <DataStruct/node.h>

Node *node_init(void *data, Node *parent) {
	Node *node = calloc(1, sizeof(*node));
	node->data = data;
	node->parent = parent;
	if (parent != NULL) {
		node->compare = parent->compare;
		node->print = parent->print;
	}
	return node;
}

Node *node_addChild(Node *node, void *data) {
	node->degree += 1;
	
	if (node->children == NULL) {
		node->children = calloc(node->degree, sizeof(node->children));
	} else {
		node->children = realloc(node->children, node->degree * sizeof(node->children));
	}
	
	node->children[node->degree - 1] = node_init(data, node);
	
	return node->children[node->degree - 1];
}

Node *node_addChildren(Node *node, size_t noOfChild, ...) {
	node->degree += noOfChild;
	
	/* we could have used node_addChild but the reason we are not using it is
	 * it will call realloc too many times which makes the program slow*/
	
	if (node->children == NULL) {
		node->children = calloc(node->degree, sizeof(Node **));
	} else {
		node->children = realloc(node->children, node->degree * sizeof(Node **));
	}
	
	Node **children = node->children;
	va_list _children_data;
	va_start(_children_data, noOfChild);
	
	for (size_t i = node->degree - noOfChild; i < node->degree; i++) {
		children[i] = node_init(va_arg(_children_data, void*), node);
	}
	
	return children[node->degree - noOfChild];
}

void node_free(Node *node) {
	if (node != NULL) {
		for (size_t i = 0; i < node->degree; i++) {
			node_free(node->children[i]);
		}
		free(node);
	}
}

