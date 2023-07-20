#include <stdio.h>
int main()
{
    char c;
    int flag = 0, cnt = 0,x=0;
    while (scanf("%c", &c)!=EOF)
    {   
        if (c == '\n')
            break;
        if (c == '(')
            flag++;
        if (c == ')')
            flag--;
        if (flag < 0)
        {
            cnt++;
            flag = 0;
        }
        x++;
        
    }
    cnt += flag;
    printf("%d\n", x-cnt);

    return 0;
}