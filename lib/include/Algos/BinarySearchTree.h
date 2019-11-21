/**
# Created By: Anonymous Noman
# Created On: 11/16/2019; 10:36 PM
*/
#ifndef OFFICIAL_BINARYSEARCHTREE_H
#define OFFICIAL_BINARYSEARCHTREE_H

#include <stdInclude.h>
#include <DataStruct/node.h>

Node *bst_init(int (*compare)(void *thisData, void *data), int (*print)(void *data));

Node *bst_getLeft(Node *node);

Node *bst_getRight(Node *node);

Node *bst_getRoot(Node *node);


void bst_insert(Node *root, void *data);

void bst_delete(Node *root, Node *node);


Node *bst_search(void *data);

Node *bst_recursiveSearch(void *data);

Node *bst_minimum(Node *root);

Node *bst_maximum(Node *root);

Node bst_successor(Node *root, ...);

Node bst_predecessor(Node *root, ...);


void bst_preOrderWalk(Node *root);

void bst_inOrderWalk(Node *node);

void bst_recursiveInOrderWalk(Node *node);

void bst_postOrderWalk(Node *root);


bool isBinarySearchTree(Node *root);

void bst_visualize(Node *root, char orientation);

#endif //OFFICIAL_BINARYSEARCHTREE_H
