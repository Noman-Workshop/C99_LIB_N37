/**
# Created By: Noman^Alien#0637 
# Created On: 4/9/2019; 9:44 AM
*/

#include "Util/string.h"

char *toggleCase(const char *str) {
	int i;
	int strLength = strlen(str);
	char *toggleStr = (char *) calloc(strLength, sizeof(char));
	for (i = 0; i < strLength; i++) {
		if (str[i] > 'a')
			toggleStr[i] = str[i] - 'a' + 'A';
		else
			toggleStr[i] = str[i] - 'A' + 'a';
	}
	
	return toggleStr;
}
