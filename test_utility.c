/* test utility functions */
#include <stdio.h>

#include "utility.h"

int main() {
    /* test for gcd  */
    printf("GCD(50, 15) = %u\n", gcd(50, 15));
    printf("GCD(1989, 1590) = %u\n", gcd(1989, 1590));

    /* test for quickpow */
    printf("quickpow(12, 3) = %ld\n", quickpow(12, 3));
    printf("quickpow(2, 12) = %ld\n", quickpow(2, 12));

    /* test for binary search */
    int A[] = {1, 3, 4, 67, 99, 102};
    printf("search `3`, result: %d\n", binarySearch(A, 3, 6));
    printf("search `67`, result: %d\n", binarySearch(A, 67, 6));
    printf("search `101`, result: %d\n", binarySearch(A, 101, 6));

    return 0;
    
}
