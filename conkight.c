#include <stdio.h>
#define max(i, j) (i > j ? i : j)
int X[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int Y[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int main()
{
    int value[8][8], px, py;
    char c;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {

            scanf("%c", &c);
            if (c == '.')
                value[i][j] = 0;
            if (c == 'P')
                value[i][j] = 1;
            if (c == 'B')
                value[i][j] = 3;
            if (c == 'K')
                value[i][j] = 5;
            if (c == 'R')
                value[i][j] = 3;
            if (c == 'Q')
                value[i][j] = 8;
            if (c == 'A')
                value[i][j] = 10;
            if (c == '0')
            {
                px = i, py = j;
            }
        }
        scanf("%c", &c);
    }
    int ans = 0;
    for (int i = 0; i < 8; i++)
    {
        int x = px + X[i];
        int y = py + Y[i];
       
        if (x >= 0 && y >= 0 && x < 8 && y < 8)
        {   
            
            for (int j = 0; j < 8; j++)
            {
                int xx = x + X[j];
                int yy = y + Y[j];
                if (xx >= 0 && yy >= 0 && xx < 8 && yy < 8 && x!=xx && y!=yy)
                   {    
                     ans = max(ans, value[x][y]+value[xx][yy]);
                   }
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}