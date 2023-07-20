#include <stdio.h>
int arr[10000000];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int m;
    scanf("%d", &m);
    char c;
    scanf("%c", &c);
    while (m--)
    {
        scanf("%c", &c);
        if (c == 'I')
        {
            int x;
            scanf("%d", &x);
            for (int i = 0; i < n; i++)
                arr[i] += x;
        }
        if (c == 'D')
        {
            int x;
            scanf("%d", &x);
            for (int i = 0; i < n; i++)
                arr[i] -= x;
        }
        if (c == 'P')
        {
            for (int i = 0; i < n; i++)
            {
                if (i == n - 1)
                {
                    printf("%d\n", arr[i]);
                }
                else
                {
                    printf("%d ", arr[i]);
                }
            }
        }
        scanf("%c", &c);
    }
    return 0;
}