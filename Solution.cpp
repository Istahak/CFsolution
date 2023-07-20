#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    char grid[n + 1][m + 1];
    int x = 1e9, y = -1e9, p = 1e9, q = -1e9;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == '#')
            {
                x = min(i, x), y = max(i, y);
                p = min(j, p), q = max(j, q);
            }
        }
    }

    for (int i = x; i <= y; i++)
    {
        for (int j = p; j <= q; j++)
        {
            if (grid[i][j] == '.')
            {
                cout << i << ' ' << j << endl;
                return;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}