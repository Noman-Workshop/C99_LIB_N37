/**
# Created By: Noman^Alien#0637 
# Created On: 8/10/2018; 9:06 AM
*/

#include <Algos/linkedList.h>

/*======================================== Linked List Function ===================================*/

Node *ll_init(size_t noOfElements, ...) {
	assert(noOfElements && "Empty Linked List creation is NOT ALLOWED.");
	
	va_list args;
	va_start(args, noOfElements);
	
	Node *node = malloc(sizeof(Node));
	Node *head = node;
	for (size_t i = 0; i < noOfElements - 1; i++) {
		node->data = va_arg(args,
		                    void *);
		node->next = malloc(sizeof(Node));
		node = node->next;
	}
	// Configuring the last node manually to avoid
	// probable memory leak and thus endless linked list
	node->data = va_arg(args,
	                    void *);
	node->next = NULL;
	return head;
}

size_t ll_length(Node *head) {
	size_t len;
	for (len = 0; head; len++) {
		head = head->next;
	}
	return len;
}

Node *ll_getNode(Node *head, long index) {
	if (index < 0) return NULL;
	for (long i = 0; i < index && head; i++) {
		head = head->next;
	}
	return head;
}

void _ll_insert(Node **head, long index, TYPE data) {
	Node *prev, *current, *next;
	
	prev = ll_getNode(*head, index - 1);
	next = ll_getNode(*head, index);
	
	assert((prev || next) && "New Node cannot be inserted with no adjacent nodes at specified index");
	
	current = malloc(sizeof(Node));
	current->data = data;
	current->next = next;
	
	if (prev) prev->next = current;
	else *head = current;
}

Node *ll_remove(Node **head, long index) {
	
	Node *node = ll_getNode(*head, index);
	// Empty linked list
	if (!node) return NULL;
	
	Node *prev = ll_getNode(*head, index - 1);
	
	if (prev) prev->next = node->next;
		// If previous node doesn't exist then node is the current HEAD
	else *head = node->next;
	
	// Removing all connections from node
	node->next = NULL;
	
	return node;
}

void _ll_append(Node *head, TYPE data) {
	
	while (head->next) head = head->next;
	
	// head->next is the last head
	head->next = malloc(sizeof(Node));
	head->next->data = data;
	head->next->next = NULL;
}

long ll_getIndex(Node *head, TYPE data, int (*isEqual)(TYPE, TYPE)) {
	long i = 0;
	while (head && isEqual(head->data, data) != 1) {
		head = head->next;
		i++;
	}
	if (!head) return -1;
	
	return i;
}

Node *ll_copy(Node *srcHead) {
	Node *destHead = ll_init(1, srcHead->data);
	for (; srcHead->next;) {
		srcHead = srcHead->next;
		ll_append(destHead, srcHead->data);
	}
	return destHead;
}

void ll_free(Node *head) {
	Node *temp;
	while (head) {
		temp = head->next;
		free(head);
		head = temp;
	}
}
