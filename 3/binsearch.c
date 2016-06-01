#include <stdio.h>

int binsearch(int x, const int array[], int n);

int main()
{
    int array[] = {1,3,4,5,7,9,12,12,12,12,23,24,188,188,188,234,21234,21234,21234};
    int array_n = sizeof(array) / sizeof(*array);
    printf("%d\n", -1 == binsearch(35, array, array_n));
    printf("%d\n", 12 == binsearch(188, array, array_n));
    printf("%d\n", 0 == binsearch(1, array, array_n));
    printf("%d\n", 6 == binsearch(12, array, array_n));

    return 0;
}

int binsearch(int x, const int a[], int n)
{
    if (n == 0)
        return -1;

    int low = 0, high = n - 1, mid;
    while (low != high)
    {
        mid = (high + low) / 2;
        if (x > a[mid])
            low = mid + 1;
        else
            high = mid;
    }
    if (x == a[low])
        return low;
    return -1;
}
