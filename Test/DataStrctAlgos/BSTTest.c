/**
# Created By: Anonymous Noman
# Created On: 11/21/2019; 2:41 AM
*/
#include <Algos/BinarySearchTree.h>

int compare(void *a, void *b) {
	int valA = (int) a;
	int valB = (int) b;
	if (valA > valB) return 1;
	else if (valA < valB) return -1;
	else return 0;
}

int print(void *data) {
	return printf("%d", (int) data);
}

int main() {
	Node *root = bst_init(compare, print);
	bst_insert(root, (void *) 12);
	bst_insert(root, (void *) 5);
	bst_insert(root, (void *) 18);
	bst_insert(root, (void *) 2);
	bst_insert(root, (void *) 9);
	bst_insert(root, (void *) 15);
	bst_insert(root, (void *) 19);
	bst_insert(root, (void *) 13);
	bst_insert(root, (void *) 17);
	bst_recursiveInOrderWalk(root);
	node_free(root);
	
}
