#include <stdio.h>
#define max(i, j) (i > j ? i : j)
int arr[100000000];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    long long int ans = 0, sum = 0;
    int i = 0;
    for (; i < n; i++)
    {
        sum += arr[i];
        ans = max(ans, sum);
        if (sum < 0)
        {
            sum = 0;
        }
    }
    printf("%lld\n",ans);

return 0;    
}
