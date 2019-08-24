/**
# Created By: Noman^Alien#0637 
# Created On: 8/10/2018; 9:06 AM
*/

#include <Util/linkedList.h>

/*========================================Linked List Function===================================*/

//Node *ll_init(TYPE firstNode) {
//	Node *ll = malloc(sizeof(Node));
//	ll->data = firstNode;
//	ll->next = NULL;
//	return ll;
//}


size_t ll_length(Node *ll) {
	int i;
	for (i = 0; ll; i++) {
		ll = ll->next;
	}
	
	return i;
	
}

//Node *ll_ithNode(Node *ll, int pos) {
//}
//
//Node *ll_copy(Node *ll) {
//}
//
//void *ll_insert(Node *ll, int pos, TYPE node) {
//}
//
void *ll_append(Node *ll, Node elem) {

}

//void ll_print(Node *ll) {
//}
//
//Node *ll_fromArray(TYPE*arr, int lenArr) {
//}
//
//TYPE*ll_toArray(Node *ll) {
//}
