#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int k = i;
        int pre = k % 10;
        int nxt = k % 10;
        int ok = 1;
        while (k != 0)
        {
            pre = nxt;
            nxt = k % 10;
            k /= 10;
            if (nxt != pre)
            {
                ok = 0;
                break;
            }
        }
        if (ok == 1)
        {
            printf("%d\n", i);
        }
    }
    return 0;
}