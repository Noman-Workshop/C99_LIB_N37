/**
# Created By: Noman^Alien#0637 
# Created On: 8/10/2018; 9:06 AM
*/

#include <Util/linkedList.h>

/*======================================== Linked List Function ===================================*/

LList *ll_init(size_t noOfElements, ...) {
	if (noOfElements <= 0) {
		return NULL;
	}
	
	va_list args;
	va_start(args, noOfElements);
	
	Node *node = malloc(sizeof(LList));
	Node *head = node;
	for (size_t i = 0; i < noOfElements - 1; i++) {
		node->data = va_arg(args, void *);
		node->next = malloc(sizeof(Node));
		node = node->next;
	}
	// Configuring the last node manually to avoid
	// probable memory leak and thus endless linked list
	node->data = va_arg(args, void *);
	node->next = NULL;
	return head;
}

size_t ll_length(Node *node) {
	size_t len;
	for (len = 0; node; len++) {
		node = node->next;
	}
	return len;
}

Node *ll_getNode(LList *ll, size_t pos) {
	Node *node = ll;
	for (size_t i = 0; i < pos && ll; i++) {
		node = node->next;
	}
	return node;
}

TYPE ll_getData(LList *ll, size_t pos) {
	return ll_getNode(ll, pos)->data;
}

LList *ll_copy(LList *ll) {
	return NULL;
}

void _ll_insert(LList *ll, size_t pos, TYPE data) {
	Node *prev, *current;
	if (!pos) prev = NULL;
	else prev = ll_getNode(ll, pos - 1);
	
	current = malloc(sizeof(Node));
	current->data = data;
	current->next = ll_getNode(ll, pos);
	
	if (prev) prev->next = current;
	
}

void _ll_append(LList *ll, TYPE data) {
	while (ll->next) {
		ll = ll->next;
	}
	ll->next = malloc(sizeof(Node));
	Node *lastNode = ll->next;
	lastNode->data = data;
	lastNode->next = NULL;
}

