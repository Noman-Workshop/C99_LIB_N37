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

void bst_setChild(Node *node, void *data, const char *child) {
	if (node != NULL) {
		if (node->children == NULL) {
			node->children = calloc(2, sizeof(node->children));
		}
		if (bst_getChild(node, child) == NULL) {
			node->children[_bst_interpretChildStr(child)] = node_init(data, node);
		} else {
			node->children[_bst_interpretChildStr(child)]->data = data;
		}
		node->degree += 1;
	} else {
		// fixme: Raise an exception when node is NULL i.e. not defined
	}
	
}

Node *bst_getChild(Node *node, const char *child) {
	if (node != NULL && node->children != NULL) {
		return node->children[_bst_interpretChildStr(child)];
	}
	// fixme: Raise an exception when node and its children is not defined
	return NULL;
}

void bst_insert(Node *root, void *data) {
	if (root != NULL && root->parent == NULL) {
		
		while (root->data != NULL) {
			int compareVal = root->compare(root->data, data);
			switch (compareVal) {
				case 1:
					if (bst_getChild(root, LEFT) == NULL) { bst_setChild(root, NULL, LEFT); }
					root = bst_getChild(root, LEFT);
					break;
				case 0:
					break;
				case -1:
					if (bst_getChild(root, RIGHT) == NULL) { bst_setChild(root, NULL, RIGHT); }
					root = bst_getChild(root, RIGHT);
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

Node *bst_search(Node *node, void *data) {
	while (node != NULL) {
		int nodeVsData = node->compare(node->data, data);
		switch (nodeVsData) {
			case 1:
				node = bst_getChild(node, LEFT);
				break;
			case 0:
				return node;
			case -1:
				node = bst_getChild(node, RIGHT);
				break;
			default:
				// fixme: raise an exception for unknown comparison value
				break;
		}
	}
	return NULL;
}

Node *bst_recursiveSearch(Node *node, void *data) {
	if (node == NULL || node->compare(node->data, data) == 0) {
		return node;
	} else if (node->compare(node->data, data) == 1) {
		return bst_recursiveSearch(bst_getChild(node, LEFT), data);
	} else {
		return bst_recursiveSearch(bst_getChild(node, RIGHT), data);
	}
}

Node *bst_minimum(Node *node) {
	if (node != NULL) {
		while (node->children != NULL && bst_getChild(node, LEFT) != NULL) {
			node = bst_getChild(node, LEFT);
		}
		return node;
	}
	// fixme: throw an exception when node is not defined i.e NULL
	return NULL;
}

Node *bst_maximum(Node *node) {
	if (node != NULL) {
		while (node->children != NULL && bst_getChild(node, RIGHT) != NULL) {
			node = bst_getChild(node, RIGHT);
		}
		return node;
	}
	// fixme: throw an exception when node is not defined i.e NULL
	return NULL;
}

void bst_recursiveInOrderWalk(Node *node) {
	if (node != NULL) {
		bst_recursiveInOrderWalk(bst_getChild(node, LEFT));
		node->print(node->data);
		printf(", ");
		bst_recursiveInOrderWalk(bst_getChild(node, RIGHT));
	}
}

unsigned short _bst_interpretChildStr(const char *child) {
	switch (tolower(child[0])) {
		case 'l':
			return 0;
		case 'r':
			return 1;
		default:
			// fixme: Raise an exception when child char is not either left or right
			return -1;
	}
	
}
