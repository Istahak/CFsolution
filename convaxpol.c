#include <stdio.h>
int x[10000000], y[10000000];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &x[i], &y[i]);
    }
    int area;
    for (int i = 2; i < n; i++)
    {
        area = (x[i - 2] * y[i - 1] + x[i - 1] * y[i] + x[i] * y[i - 2]);
        area -= (y[i - 2] * x[i - 1] + y[i - 1] * x[i] + y[i] * x[i - 2]);
        if (area < 0)
            m--;
        if (m == -1)
        {
            puts("No convex polygon possible");
            return 0;
        }
    }
    puts("Convex polygon exists");

    return 0;
}