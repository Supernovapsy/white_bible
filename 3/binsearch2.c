// Practise again.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binsearch(int* array, int length, int target);

int main(int argv, char** argc) {
    const int numN = argv - 1;
    int nums[numN];
    int i;
    for (i = 1; i < argv; ++i)
        nums[i - 1] = atoi(argc[i]);
    int target = nums[0];

    printf("%d %sfound.\n", target, binsearch(nums + 1, numN - 1, target) ? "" : "not ");
}

// 2, 3, 1 - 1
int binsearch(int* a, int l, int t) {
    int i;
    if (l <= 0)
        return 0;
    else if (l == 1)
        return a[0] == t;
    int mid = l / 2;
    int m = a[mid];
    if (t < m)
        return binsearch(a, mid, t);
    else
        return binsearch(a + mid, l - mid, t);
}
