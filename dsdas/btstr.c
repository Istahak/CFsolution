#include <stdio.h>
char s[100000];
void bitstr(int x)
{
    if (x == 0)
    {
        for (int i = 0; s[i] != '\0'; i++)
            printf("%c", s[i]);

        return;
    }
    for (int i = 0; s[i] != '\0'; ++i)
    {
        if (x & 1)
        {
            if (s[i] == '0')
            {
                printf("%c", s[i]);
            }
            else
            {
                bitstr(x - 1);
            }
        }
        else
        {
            if (s[i] == '1')
            {
                printf("%c", s[i]);
            }
            else
            {
                bitstr(x - 1);
            }
        }
    }
}

int main()
{
    int x;
    scanf("%s", s);
    scanf("%d", &x);
    bitstr(x);
    printf("\n");
    return 0;
}