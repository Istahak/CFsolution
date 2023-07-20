#include <bits/stdc++.h>
#define ll long long int
using namespace std;
char grid[101][101];
int n, m, r, k;
void solve()
{
    cin >> n >> m >> r >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> grid[i][j];
        }
    }
    while (r--)
    {
        int x, y;
        char d;
        cin >> x >> y >> d;
        int t = k;
        while (t--)
        {
            if (d == 'U' || d == 'D')
            {
                if (x == n && d == 'D')
                    d = 'U';
                else if (x == 1 && d == 'U')
                    d = 'D';
                else if (grid[x - 1][y] == '#' && d == 'U')
                    d = 'D';
                else if (grid[x + 1][y] == '#' && d == 'D')
                    d = 'U';
                else if (d == 'D')
                    x++;
                else
                    x--;
            }
            else
            {
                if (y == m && d == 'R')
                    d = 'L';
                else if (y == 1 && d == 'L')
                    d = 'R';
                else if (grid[x][y - 1] == '#' && d == 'L')
                    d = 'R';
                else if (grid[x][y + 1] == '#' && d == 'R')
                    d = 'L';
                else if (d == 'R')
                    y++;
                else
                    y--;
            }
        }
        cout << x << ' ' << y << ' ' << d << endl;
    }
}
int main()
{

    int t = 1;
    // cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }

    return 0;
}