/**
# Created By: Noman^Alien#0637 
# Created On: 8/10/2018; 9:06 AM
*/

#include <stdInclude.h>

#define TYPE void *
/*======================================== Linked List Struct ===================================*/

/**
 * Generic Linked List Data Structure
 * @param data 	Generic Pointer to data present in current node
 * @param next 	Pointer of adjacent node
 * @attention 	LList and Node are used synonymously according to the context
 */
typedef struct Node {
	TYPE data;
	struct Node *next;
} Node, LList;

/*======================================== Linked List Function ===================================*/

/**
 * @brief 				Initialize an Linked List with any number of elements
 * @param noOfElements 	No of Elements to be initialized with
 * @param ...			New data of the linked list
 * @returns 			Pointer to the HEAD of linked list
 */
Node *ll_init(size_t noOfElements, ...);

/**
 * @param head 	Pointer to the HEAD of linked list
 * @returns 	Length of linked list
 */
size_t ll_length(Node *head);

/**
 * @param head 	Pointer to the HEAD of linked list
 * @param index Index of the node to get
 * @returns 	The node at given index
 */
Node *ll_getNode(Node *head, long index);

/**
 * @param head 	Pointer to the HEAD of linked list
 * @param index Index of the data to get
 * @returns 	The data at given index
 */
#define ll_getData(head, index) ll_getNode(head, index)->data

/**
 * @brief 		Inserts a new element at given index of a linked list
 * @param head 	Address of the HEAD of linked list
 * @param index Index at which new Node is to be inserted
 * @param data 	Generic Pointer to the data of new Node
 */
void _ll_insert(Node **head, long index, TYPE data);

/**
 * @brief 		Inserts a new element at given index of a linked list
 * @param ll 	Address of the HEAD of linked list
 * @param index Index at which new Node is to be inserted
 * @param data 	Data of new Node
 */
#define ll_insert(head, index, data) _ll_insert(&head, index, (TYPE) data)

/**
 * @brief 		Pushes a New Node at the beginning of the list
 * @param ll 	Address of the HEAD of linked list
 * @param data 	Data of new Node
 * @returns 	Pointer to Newly formed Linked List
 */
#define ll_push(head, data) _ll_insert(&head, 0, (TYPE) data)

/**
* @brief 		Removes element at given index of a linked list
* @param head 	Address of the HEAD of linked list
* @param index 	Index of the node which is to removed
* @returns 		The removed Node
*/
Node *ll_remove(Node **head, long index);

/**
* @brief 		Removes the HEAD node of supplied linked list
* @param head 	Address of the HEAD of linked list
* @returns 		The HEAD of old linked list
*/
#define ll_pop(ll) ll_remove(&ll, 0)

/**
 * @brief		Inserts new node at the end of the linked list
 * @param head 	Pointer to the HEAD of linked list
 * @param data 	Generic Pointer to the data of new Node
 */
void _ll_append(Node *head, TYPE data);

/**
 * @brief		Inserts new node at the end of the linked list
 * @param head 	Pointer to the HEAD of linked list
 * @param data  Data of new Node
 */
#define ll_append(head, data) _ll_append(head, (TYPE) data)

/**
 *
 * @param head 		Pointer to the HEAD of linked list
 * @param data 		The Data to search for in linked list
 * @param isEqual 	Function Pointer to check equality of two generic data pointers
 * @return 			Index of the Node in which Data is found <br>
 * 					Or -1 if data is not
 */
long ll_getIndex(Node *head, TYPE data, int (*isEqual)(TYPE, TYPE));

/**
 * @param head	Pointer to the HEAD of the linked list
 * @param fmt	?
 * @param sep	Separator between two data
 * @param end	?
 * @param cast	?
 * fixme: Find a better alternative of this macro
 */
#define ll_print(head, fmt, sep, end, cast)                 \
    do {                                                    \
        for(Node *temp = head; temp; temp = temp->next){    \
            printf(fmt sep, (cast) temp->data);             \
        }                                                   \
        printf(end);                                        \
    } while (0)                                             \

/**
 * @brief 			copies the supplied linked list into a new memory
 * @param srcHead 	Pointer to the HEAD of the linked list
 * @return 			Pointer to the HEAD of the copied linked list
 */
Node *ll_copy(Node *srcHead);


/**
 * @brief 		Free's the whole linked list starting from HEAD
 * @param head 	Pointer to the HEAD of linked list
 */
void ll_free(Node *head);
/**
 * @brief 			Free's a specific node at given index
 * @param head 		Address of the HEAD of linked list
 * @param index 	Index of the node which is to removed
 */
#define ll_freeNode(head, index) free(ll_remove(head, index))

