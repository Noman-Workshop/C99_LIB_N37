/**
# Created By: Noman^Alien#0637 
# Created On: 4/9/2019; 10:54 AM
*/

#include <stdio.h>
#include <Util/string.h>

int main() {
	
	const char *hello = toggleCase("Hello");
	printf("Hello: %s", hello);
	free((void *) hello);
	
	return 0;
}


