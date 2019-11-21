/**
# Created By: Anonymous Noman
# Created On: 11/20/2019; 7:50 PM
*/

#include <DataStruct/node.h>


int main() {
	
	Node *a = node_init((void *) 5, NULL);
	node_addChildren(a, 2, 5, 6);
	node_addChildren(a->children[1], 2, 23, 25);
	node_free(a);
	return 0;
}
