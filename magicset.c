// 16
// 16
#include <stdio.h>
#include <math.h>
int arr[1000];
void bsort(int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

int main()
{
    int n;
    scanf("%d", &n);
    if (n == 0)
    {
        printf("\n");
        return 0;
    }
    if (n == 1)
    {
        scanf("%d", &arr[0]);
        printf("%d\n", arr[0]);
        return 0;
    }
    int pos = 0, neg = 0, zero = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i] > 0)
            pos++;
        if (arr[i] < 0)
            neg++;
        if (arr[i] == 0)
            zero++;
    }
    if (zero == n || (pos == 0 && zero && neg == 1))
    {
        bsort(n);
        for (int i = 0; i < n; i++)
        {
            if (i != (n - 1))
                printf("%d ", arr[i]);
            else
                printf("%d\n", arr[i]);
        }
        return 0;
    }
    if (neg & 1)
    {
        bsort(n);
        for (int i = 0; i < n; i++)
        {
            if (neg == 1)
            {
                neg--;
                continue;
            }
            if (arr[i] == 0)
                continue;
            if (i != (n - 1))
                printf("%d ", arr[i]);
            else
                printf("%d\n", arr[i]);
            if (arr[i] < 0)
                neg--;
        }
        return 0;
    }
    bsort(n);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            continue;
        if (i != (n - 1))
            printf("%d ", arr[i]);
        else
            printf("%d\n", arr[i]);
    }
    return 0;
}
