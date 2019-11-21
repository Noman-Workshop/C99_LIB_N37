/**
# Created By: Anonymous Noman
# Created On: 11/16/2019 10:36 PM
*/

#include <Algos/BinarySearchTree.h>

Node *bst_init(int (*compare)(void *thisData, void *data), int (*print)(void *data)) {
	Node *root = node_init(NULL, NULL);
	root->compare = compare;
	root->print = print;
	return root;
}

Node *bst_getLeft(Node *node) {
	if (node != NULL && node->children != NULL) {
		return node->children[0];
	}
	// fixme: Raise an exception when node and its children are not defined
	return NULL;
}

Node *bst_getRight(Node *node) {
	if (node != NULL && node->children != NULL) {
		return node->children[1];
	}
	// fixme: Raise an exception when node and its children is not defined
	return NULL;
}

Node *bst_getRoot(Node *node) {
	if (node != NULL) {
		while (node->parent != NULL) {
			node = node->parent;
		}
		return node;
	}
	// fixme: Raise an exception when node is not defined
	return NULL;
}

void bst_insert(Node *root, void *data) {
	if (root != NULL && root->parent == NULL) {
		
		while (root->data != NULL) {
			if (root->children == NULL) {
				root->children = calloc(2, sizeof(root->children));
			}
			int compareVal = root->compare(root->data, data);
			switch (compareVal) {
				case 1:
					if (bst_getLeft(root) == NULL) root->children[0] = node_init(NULL, root);
					root = bst_getLeft(root);
					break;
				case 0:
					break;
				case -1:
					if (bst_getRight(root) == NULL) root->children[1] = node_init(NULL, root);
					root = bst_getRight(root);
					break;
				default:
					// fixme: raise an exception for unknown comparison value
					break;
				
			}
		}
		root->data = data;
		
	}
	// fixme: Raise an exception when root is not defined or its not root
}

void bst_recursiveInOrderWalk(Node *node) {
	if (node != NULL) {
		bst_recursiveInOrderWalk(bst_getLeft(node));
		node->print(node->data);
		printf(", ");
		bst_recursiveInOrderWalk(bst_getRight(node));
	}
	
}



