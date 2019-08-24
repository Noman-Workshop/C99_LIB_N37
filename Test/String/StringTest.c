/**
# Created By: Noman^Alien#0637 
# Created On: 4/9/2019; 10:54 AM
*/

#include <Util/String/string.h>

int main() {
	
	const char *hello = str_toggleCase("Hello, Hi I am No One, This is Me");
//	printf("Toggled: %s\n", hello);
	char **tokens = str_split(hello, " ");
//
//	const char *word = "bbba5bbbb";
//	char **tokens = str_split(word, "bbb");
//	printf("word: %s\n", word);
	for (int i = 0; i <= **tokens - '0'; i++) {
		printf("\"%s\" --> %d\n", tokens[i], (int) strlen(tokens[i]));
	}
	
	char *s = str_trim("aaaa55cvaabbaaaaa", "aa");
	printf("\"%s\", %d", s, (int) strlen(s));
	
	free(s);
	free(tokens);
	return 0;
}


