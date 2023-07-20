#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int cnt = 0;
    int k = n;
    int M=1;
    while (k != 0)
    {
        k /= 10;
        cnt++;
        M=M*10;
    }
    int evenposnum = 0, newnum = 0;
    k = n;
    while (cnt != 0)
    {
        if (cnt % 2 == 0)
        {
            int currentnum = k % M;
            int currentdigit = 0;
            int x = 0;
            while (currentnum != 0)
            {
                currentdigit = currentnum % 10;
                currentnum = currentnum / 10;
                x++;
            }
            if (x == cnt)
            {
                evenposnum = evenposnum * 10 + currentdigit;
                newnum = newnum * 10 + 9;
            }
            else
            {
                evenposnum = evenposnum * 10 + 0;
                newnum = newnum * 10 + 9;
            }
        }
        cnt--;
        M=M/10;
    }
    int ans = newnum - evenposnum;
    printf("%d\n", ans);

    return 0;
}