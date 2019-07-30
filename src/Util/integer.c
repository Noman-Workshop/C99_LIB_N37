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

Boolean isPrime(unsigned INTEGER num) {
	INTEGER i;
	
	if (num <= 3) {
		return num > 1;
	} else if (num % 2 == 0 || num % 3 == 0) {
		return false;
	}
	
	for (i = 5; i * i <= num; i += 6) {
		if (num % i == 0 || num % (i + 2) == 0) {
			return false;
		}
	}
	
	return true;
	
}

Boolean isPerfectSquare(unsigned INTEGER num) {
	int l, r, m;
	
	if (num <= 1) {
		return true;
	}
	
	for (r = 2; r * r < num; r *= 2);
	if (r * r == num) {
		return true;
	}
	
	for (l = r / 2, m = (l + r) / 2; r - l != 1; m = (l + r) / 2) {
		if (num == m * m) {
			return true;
		} else if (num > m * m) {
			l = m;
		} else {
			r = m;
		}
		
	}
	
	return false;
}
