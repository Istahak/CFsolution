#include <stdio.h>
int main()
{
    int date;
    char c;
    scanf("%d", &date);
    while (scanf("%c", &c))
    {
        if (c == '\n')
            break;
    }
    puts(date == 21 ? "International Mother Language Day!" : "I don’t care!");
    return 0;
}