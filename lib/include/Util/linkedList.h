/**
# Created By: Noman^Alien#0637 
# Created On: 8/10/2018; 9:06 AM
*/

#include <stdInclude.h>

#define TYPE void *
/*========================================Linked List Struct===================================*/

/**
 * Generic Linked List Node
 * @param data 	the element in the head
 * @param next 	the tail of the linked list
 * @attention LList and Node
 */
typedef struct Node {
	TYPE data;
	struct Node *next;
} LList, Node;

/*========================================Linked List Function===================================*/

/**
 * @brief Initialize an Linked List
 * @return a linked list struct
 */
LList *ll_init(size_t noOfElem, ...);

/**
 * @brief returns the depth of a linked list
 * @param ll the linked list struct to get the length of
 * @return the length of linked list
 */
size_t ll_length(LList *ll);

/**
 * @brief
 * @param ll the linked list
 * @param pos the position to get or the <b> depth to reach</b>
 * @return the linked list from head
 */
Node *ll_ithNode(LList *ll, int pos);

/**
 * @brief copies the linked list into a new memory
 * @param ll the linked list to copy
 * @return the copied linked list with a new location in memory
 */
LList *ll_copy(Node *ll);

/**
 * @brief
 * @param ll the source list
 * @param pos the depth at to be inserted
 * @param node the value of the elem for the head
 * @return a new copy of the inserted list
 * @warning this doesn't change the <b>orginal list</b>
 */
void *ll_insert(Node *ll, int pos, TYPE node);

/**
 * @brief
 * @param ll the original list
 * @param elem the value of the element that is appended
 * @return a new copy appended list
 */
void *ll_append(Node *ll, Node elem);

/**
 * @brief prints all the elements of a list
 * @param ll the list to be read
 */
void ll_print(Node *ll);

/**
 * @brief transforms a full array to linked List
 * @param arr to be read
 * @param lenArr the length of the array
 * @return a new copy of list with all values of array in order
 */
Node *ll_fromArray(TYPE*arr, int lenArr);

/**
 * @brief transforms a full linked list into array
 * @param ll the linked list to be read
 * @return a new array identical to the values of the linked list
 */
TYPE*ll_toArray(Node *ll);

