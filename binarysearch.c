/* binary search function */

int binarySearch(const int A[], int x, int n) {
    /* A is a sorted sequence */
    int low = 0, high = n-1;

    while (high >= low) {
	int center = (low + high) / 2;
	if (A[center] > x)
	    high = center - 1;
	else if (A[center] < x)
	    low = center+1;
	else
	    return center;
    }

    return -1;			/* not found */
}
