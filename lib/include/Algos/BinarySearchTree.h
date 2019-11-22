/**
# Created By: Anonymous Noman
# Created On: 11/16/2019; 10:36 PM
*/
#ifndef OFFICIAL_BINARYSEARCHTREE_H
#define OFFICIAL_BINARYSEARCHTREE_H

#include <stdInclude.h>
#include <DataStruct/node.h>

#define LEFT "LEFT"
#define RIGHT "RIGHT"

/**
 * Initializes an Binary Search Tree with only Compare and Print function properties defined.
 * @param compare The function to compare between the Data of two Nodes.
 * @param print The function that prints the data of the Node
 * @return 	The Root Node of a Binary Search Tree where,					<br>
 * 			Data, Children and Parent are NULL
 * 			which also implies that degree and depth is 0.
 *
 */
Node *bst_init(int (*compare)(void *thisData, void *data), int (*print)(void *data));

/**
 * @param node A Binary Search Tree Node
 * @return The root of the Node
 * @throws NullPointerException when node is NULL i.e. not defined
 */
Node *bst_getRoot(Node *node);

/**
 * This function creates additional child manually when there is no children
 * or if any particular child is NULL. It also handles the degree of Parent Node
 * and other properties automatically.
 * <br><br>
 * If there is a valid Child Node is already present then,
 * it simply changes the value of data of the old Child Node
 *
 * @param node The Parent Node
 * @param data Data to be inserted into Data of Child Node
 * @param child The string representation of Child Name i.e. "LEft" or "rIgHt"
 * 				<br><br>
 * 				ProTip: Use MACRO LEFT or RIGHT
 * @throws NullPointerException when node is NULL i.e. not defined
 */
void bst_setChild(Node *node, void *data, const char *child);

/**
 * @param node The Parent Node
 * @param child The string representation of Child Name i.e. "LEft" or "rIgHt"
 * 				<br><br>
 * 				ProTip: Use MACRO LEFT or RIGHT
 * @return The desired child of the node
 * @throws NullPointerException when node or its children is NULL i.e. not defined
 */
Node *bst_getChild(Node *node, const char *child);

int bst_calculateDepth(Node *node);

/**
 * Insert an element in a Binary Search Tree
 * @param root The Root Node of a Binary Search Tree
 * @param data The generic pointer to be inserted in the Binary Search Tree
 * @throws NullPointerException when Root is NULL i.e. not defined
 * @throws IllegalArgumentException when the Node provided is not the Root Node
 * @throws UndefinedOperationException when the compare function doesn't return either of -1, 0, 1
 */
void bst_insert(Node *root, void *data);

void bst_delete(Node *root, Node *node);


Node *bst_search(Node *node, void *data);

Node *bst_recursiveSearch(Node *node, void *data);

Node *bst_minimum(Node *node);

Node *bst_maximum(Node *node);

Node bst_successor(Node *root, ...);

Node bst_predecessor(Node *root, ...);


void bst_preOrderWalk(Node *root);

void bst_inOrderWalk(Node *node);

/**
 * Performs a recursive InOrder Tree Walk
 * and prints all the data of the Binary Search Tree
 * @param node A Binary Search Tree Node
 */
void bst_recursiveInOrderWalk(Node *node);

void bst_postOrderWalk(Node *root);


bool isBinarySearchTree(Node *root);

void bst_visualize(Node *root, char orientation);

/**
 * Interprets Binary Child Index LEFT and RIGHT to Node Children Index 0 and 1
 * @param child The string representation of Child Name i.e. "LEft" or "rIgHt"
 * 				<br><br>
 * 				ProTip: Use MACRO LEFT or RIGHT
 * @return 0 If LEFT or 1 if RIGHT
 * @throws IllegalArgumentException when the first character is neither l or r
 */
unsigned short _bst_interpretChildStr(const char *child);

#endif //OFFICIAL_BINARYSEARCHTREE_H
