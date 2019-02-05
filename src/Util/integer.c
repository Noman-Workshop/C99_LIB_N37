/**
# Created By: anonyman637
# Created On: 2/4/19; 5:27 PM
*/


#include <Util/integer.h>

char *intToStr(int num) {
	int len = (snprintf(NULL, 0, "%d", num) + 1);
	char *strNum = (char *) malloc((size_t) len);
	sprintf(strNum, "%d", num);

	return strNum;
}
