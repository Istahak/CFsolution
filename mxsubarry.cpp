#include <stdio.h>
int arr[100000];
int main()
{
    int n;
    while (scanf("%d", &n))
    {
        if (n == 0)
            return 0;

        int x;
        scanf("%d", &x);
        long long int ans = 0;
        int flag = n;
        for (int i = 0, y; i < x; i++)
        {
            scanf("%d", &y);
            if (flag > y)
            {
                ans += flag - y;
            }
            flag = y;
        }

        printf("%lld\n", ans);
    }
}