/**
# Created By: Noman^Alien#0637 
# Created On: 8/5/2019; 3:20 AM
*/

#include <Algos/linkedList.h>

#define PAUSE printf("\nPress any key to continue...\n"); getchar()

int main() {
	
	LList *list = ll_init(3, 1, 2, 3);
//      [1, 2, 3]
	ll_append(list,4);
//	    [1, 2, 3, 4]
	ll_push(list, 0);
//	    [0, 1, 2, 3, 4]
	ll_push(list, -1);
//	    [-1, 0, 1, 2, 3, 4]
	ll_insert(list, 3, 100);
//	    [-1, 0, 1, 100, 2, 3, 4]
	ll_print(list, "%d", ", ", "\n", int);
	printf("Length: %d", (int) ll_length(list));
	PAUSE;
	
	free(ll_pop(list));
//	    [0, 1, 100, 2, 3, 4]
	free(ll_pop(list));
//	    [1, 100, 2, 3, 4]
	printf("Length: %d", (int) ll_length(list));
	PAUSE;
	
	printf("%d\n", (int) ll_getData(list, 3));
	free(ll_remove(&list, 1));
//	    [1, 2, 3, 4]
	ll_freeNode(&list, 0);
//	    [2, 3, 4]
	
	LList *list1 = ll_copy(list);
	ll_free(list);
	PAUSE;
	
	size_t len = ll_length(list1);
	Node *temp = list1;
	for (size_t i = 0; i < len; i++) {
		printf("%d: %d\n", (int) i, (int) temp->data);
		temp = temp->next;
	}
	PAUSE;
	
	ll_free(list1);
	return 0;
}

