/**
# Created By: Noman^Alien#0637 
# Created On: 4/10/2019; 12:54 AM
*/

#include <Util/mathematics.h>

INTEGER abs(INTEGER num) {
	return num > 0 ? num : -num;
}

INTEGER gcd(INTEGER a, INTEGER b) {
	
	if (!((a = abs(a)) && (b = abs(b)))) {
		return abs(a - b);
	}
	
	while (b) {
		a %= b;
		if (!a) { return b; }
		b %= a;
	}
	
	return a;
	
}

INTEGER gcdRecursive(INTEGER a, INTEGER b) {
	
	if (!((a = abs(a)) && (b = abs(b)))) {
		return abs(a - b);
	}
	
	return gcd(b % a, a);
}

INTEGER lcm(INTEGER a, INTEGER b) {
	return abs(a * b) / gcd(a, b);
}

INTEGER lcmRecursive(INTEGER a, INTEGER b) {
	return abs(a * b) / gcdRecursive(a, b);
}

