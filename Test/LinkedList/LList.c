/**
# Created By: Noman^Alien#0637 
# Created On: 8/5/2019; 3:20 AM
*/

#include <Util/linkedList.h>

int main() {
	LList *ll = ll_init(6, 1, 2, "hello", 4, 5, 6);
	
	ll_append(ll, 8);
	ll_insert(ll, 3, "Noman");
	
	Node *strNode = ll_getNode(ll, 2);
	printf("%s %s\n", (char *) strNode->data, (char *) ll_getData(ll, 3));
	printf("Length: %zu\n", ll_length(ll));
	return 0;
}

