/**
# Created By: Noman^Alien#0637 
# Created On: 4/9/2019; 10:54 AM
*/

#include <Util/string.h>

int main() {

//	const char *hello = str_toggleCase("Hello, Hi I am No One, This is Me");
//	printf("Toggled: %s\n", hello);
//	char **tokens = str_split(hello, " ");

	char **tokens = str_split("bbba55bbbbbbbbbbbaa55bbbbbbbb", "bbb");
	for (int i = 0; i <= **tokens - '0'; i++) {
		printf("%s\n", tokens[i]);
	}

//	char *s = trim("aaaa   5555 55 55  aaaa", "aa");
//	printf("\"%s\", %llu", s, strlen(s));

//	free((void *) hello);
//	free(tokens);
	return 0;
}


