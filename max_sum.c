/* Max subquent sum */
#include <stdio.h>

/* utility function */
int max3(int a, int b, int c) {
    int flag1 = a>b;
    int flag2 = b>c;

    if (flag1 && flag2)
	return a;
    else if (flag1 && !flag2)
	return a>c ? a : c;
    else if (!flag1 && flag2)
	return b;
    else
	return c;
}

/* divide and conquer version. (NLogN) */
int maxsubsum(const int A[], int left, int right) {
    int maxLeftSum, maxRightSum;
    int leftBorderSum, rightBorderSum;

    if (left == right) {
	if (A[left] < 0)
	    return 0;
	else
	    return A[left];
    }

    int center = (left+right) / 2;

    maxLeftSum = maxsubsum(A, left, center);
    maxRightSum = maxsubsum(A, center+1, right);

    /* now calculate the bordersum */
    int i, curSum;
    for(i=center, leftBorderSum = 0, curSum = 0; i>=left; i--) {
	curSum += A[i];
	if (curSum > leftBorderSum)
	    leftBorderSum = curSum;
    }

    for(i=center+1, rightBorderSum = 0, curSum = 0; i<=right; i++) {
	curSum += A[i];
	if (curSum > rightBorderSum)
	    rightBorderSum = curSum;
    }

    return max3(maxLeftSum, maxRightSum, leftBorderSum+rightBorderSum);
}

/* dynamic programming version. (N) */
int maxsubSum2(const int A[], int n) {
    /* f[i] represents max subquence sum in sequence [1, i], therefore
       f[i] = max(f[i-1], sum[j, i]), j<=i && j>=1 */
    int curMax = 0;
    int curSeqSum = 0;
    for (int i=0; i<n; i++) {
	curSeqSum += A[i];
	if (curSeqSum < 0)
	    curSeqSum = 0;
	if (curMax < curSeqSum)
	    curMax = curSeqSum;
    }

    return curMax;
}

int maxSubquenceSum(const int A[], int n) {
    return maxsubsum(A, 0, n-1);
}

int main() {
    int A[] = {4, -3, 5, -2, -1, 2, 6, -2};
    int n = 8;

    printf("Max Subquence Sum (O(NLogN) version): %d\n", maxSubquenceSum(A, n));
    printf("Max Subquence Sum (O(N) version): %d\n", maxsubSum2(A, n));

    return 0;
}


