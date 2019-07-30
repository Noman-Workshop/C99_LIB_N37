/**
# Created By: anonyman637
# Created On: 2/4/19; 5:28 PM
*/

#ifndef UTIL_INTEGER_H
#define UTIL_INTEGER_H

#include <stdInclude.h>

#define INTEGER int
typedef enum {
	false, true
} Boolean;

char *intToStr(INTEGER num);

INTEGER sumDigits(INTEGER num);

Boolean isPrime(unsigned INTEGER num);

Boolean isPerfectSquare(unsigned INTEGER num);

#endif
