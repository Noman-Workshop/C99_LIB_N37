/**
# Created By: Anonymous Noman
# Created On: 11/16/2019; 10:14 PM
*/
#ifndef OFFICIAL_NODE_H
#define OFFICIAL_NODE_H

#include <stdInclude.h>

/**
 * A Node is a basic unit of a data structure, such as a linked list or tree data structure.
 * Nodes contain data and also may link to other Nodes.
 * Links between Nodes are often implemented by pointers.
 *
 * @data
 * 			As this is a generic Node data structure
 * 			so Data is a generic pointer (void*)
 *
 * @parent_children
 * 			A Child Node is a Node extending from another Node.
 * 			The inverse relationship is that of a Parent Node.
 * 			If Node C is a child of Node A, then A is the Parent Node of C.
 * 			A Parent can have multiple Child but a Child can only have a single Parent.
 * 																			<br>
 * 																			<br>
 *			Parent contains pointer to the Parent Node.						<br>
 * 			Children is pointer array of Nodes.								<br>
 * @degree
 * 			The degree of a Node is the number of Children of the Node.
 * @depth
 *			The depth of Node A is the length of the path from A to the root Node.
 *			The root Node is said to have depth 0.
 *			The depth of a Node is implementation defined.
 * @compare
 *			Compare function compares between the data of two Nodes.
 *			Compare function can have 3 basic return values which are -1, 0, 1.
 *			All other return values are implementation defined.
 *
 * @print
 * 			Prints the data of a Node.
 * 			The print function returns the no of characters printed.
 *			Print function is implementation defined.
 */
typedef struct Node {
	
	/**
	 * As this is a generic Node data structure
	 * so Data is a generic pointer (void*)
	 */
	void *data;
	
	/**
	 * A Child Node is a Node extending from another Node.
	 * The inverse relationship is that of a parent Node.
	 * A Node can only have a single Parent.
	 */
	struct Node *parent;
	
	/**
	 * The degree of a Node is the number of children of the Node.
	 */
	size_t degree;
	/**
	 * A Child Node is a Node extending from another Node.
	 * A Node can have multiple Child Nodes.
	 * Children is pointer array of Nodes.
	 */
	struct Node **children;
	/**
	 * The depth of Node A is the length of the path from A to the root Node.
	 * The root Node is said to have depth 0.
	 * The depth of a Node is implementation defined.
	 */
	int depth;
	
	/**
	 * Compare function compares between the data of two Nodes.
	 * @param valA The generic pointer of a data
	 * @param valB The generic pointer of another data
	 * @return
	 * 			Compare function must return the following values			<br>
	 * 			1  if valA > valB											<br>
	 * 			0  if valA = valB											<br>
	 * 			-1 if valA < valB											<br>
	 * 			All other return values are implementation defined.
	 */
	int (*compare)(void *valA, void *valB);
	
	/**
	 * Prints the data of a Node.
	 * Print function is implementation defined.
	 * @param data The generic pointer of the data to be printed
	 * @return Number of characters printed
	 */
	int (*print)(void *data);
} Node;

/**
 * Initializes a Node with Data and a Parent
 * @param data The generic pointer of the Data
 * @param parent The pointer to Parent Node
 * @return 	A Node whose, 													<br>
 * 			Compare and Print function are acquired from its parent.		<br>
 * 			Children is NULL which implies no allocated space for children and
 * 			degree of Node is 0												<br>
 */
Node *node_init(void *data, Node *parent);

/**
 * Allocates and add a Child Node to the end of children array of Node
 * @param node The Parent of which children array will be expanded
 * @param data The Data to be inserted in the Data property of Child Node
 * @return The pointer to the Child Node
 */
Node *node_addChild(Node *node, void *data);

/**
 * Allocates and add multiple Child Node to the end of children array of Node
 * @param node The Parent of which children array will be expanded
 * @param noOfChild Number of child nodes to be added
 * @param ... The Data values to be inserted in the Data property of Child Nodes
 * @return The pointer to the first Child Node which is added in this particular function call
 */
Node *node_addChildren(Node *node, size_t noOfChild, ...);

/**
 * Frees Node along with its children in PostOrderRecursiveWalk fashion
 * @param node the Node to be freed along with all its children
 */
void node_free(Node *node);

#endif //OFFICIAL_NODE_H
