/**
# Created By: Noman^Alien#0637 
# Created On: 8/10/2018; 9:06 AM
*/

#include <stdInclude.h>

#define TYPE void *
/*======================================== Linked List Struct ===================================*/

/**
 * Generic Linked List Data Structure
 * @param data 	Generic Pointer to Data present in current Node
 * @param next 	Generic Pointer to Data present in the adjacent Node
 * @attention 	LList and Node are used synonymously according to the context
 */
typedef struct Node {
	TYPE data;
	struct Node *next;
} LList, Node;

/*======================================== Linked List Function ===================================*/

/**
 * @brief 				Initialize an Linked List
 * @param noOfElements 	No of Elements to be initialized with
 * @param ...			Generic Pointer to the new Datas of the linked list
 * @return 				A pointer to the first Node of the Linked List
 */
LList *ll_init(size_t noOfElements, ...);

/**
 * @param node 	A linked List
 * @return 		the length of linked list
 */
size_t ll_length(LList *node);

/**
 * @param ll 	A linked list
 * @param pos 	the position to get or the <b> depth to reach</b>
 * @return 		A node at position i of linked list ll
 */
Node *ll_getNode(LList *ll, size_t pos);

/**
 * @param ll 	A linked list
 * @param pos 	the position to get or the <b> depth to reach</b>
 * @return 		Data at position i of linked list ll
 */
TYPE ll_getData(LList *ll, size_t pos);

/**
 * @brief copies the linked list into a new memory
 * @param ll the linked list to copy
 * @return the copied linked list with a new location in memory
 */
LList *ll_copy(LList *ll);

/**
 * @param ll 	Pointer to the Head of Nodes
 * @param pos 	the depth at which new Node is to be inserted
 * @param data 	Generic Pointer to the data of new Node
 */
void _ll_insert(Node *ll, size_t pos, TYPE data);

/**
 * @brief Easies the use of inserting by automating casting
 * @param ll 	Pointer to the Head of Nodes
 * @param pos 	the depth at which new Node is to be inserted
 * @param data 	Data of new Node
 */
#define ll_insert(ll, pos, data) _ll_insert(ll, pos, (TYPE) data)

/**
 * @param ll 	Pointer to the linked list head
 * @param data 	Generic Pointer to the data of new Node
 */
void _ll_append(LList *ll, TYPE data);

/**
 * @brief Easies the use of appending by automating casting
 * @param ll 	Pointer to the Head of Nodes
 * @param data 	Data of new Node
 */
#define ll_append(ll, data) _ll_append(ll, (TYPE) data)

// todo: free linked list
void ll_free(LList *ll);
