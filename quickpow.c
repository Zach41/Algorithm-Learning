#include "utility.h"

int isEven(long x) {
    return x & 1 ? 0 : 1;
}
long quickpow(long x, unsigned int n) {
    if ( n== 0)
	return 1;
    if ( n== 1)
	return x;
    
    if (isEven(n))
	return quickpow(x, n/2) * quickpow(x, n/2);
    else
	return x * quickpow(x, (n-1)/2) * quickpow(x, (n-1)/2);
}
