/**
# Created By: anonyman637
# Created On: 2/4/19; 5:27 PM
*/


#include <Util/integer.h>

char *intToStr(INTEGER num) {
	INTEGER len = (snprintf(NULL, 0, "%d", num) + 1);
	char *strNum = (char *) malloc((size_t) len);
	sprintf(strNum, "%d", num);
	
	return strNum;
}

INTEGER sumDigits(INTEGER num) {
	INTEGER sum;
	for (sum = 0; num > 0; sum += num % 10, num /= 10);
	return sum;
}

