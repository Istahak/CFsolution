#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int n, m;
char grid[300][300];
bool vis[300][300];
bool v[300][300];
int ans = 0;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void dfs(int x, int y)
{

    if (grid[x][y] == '#' or vis[x][y])
        return;
    vis[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int xx = x, yy = y;
        while (grid[xx + dx[i]][yy + dy[i]] == '.')
        {
            v[xx][yy] = true;
            xx += dx[i];
            yy += dy[i];
        }
        if (!vis[xx][yy])
            dfs(xx, yy);
    }
}
void solve()
{
    for (int i = 0; i < 300; i++)
    {
        for (int j = 0; j < 300; j++)
        {
            grid[i][j] = '#';
        }
    }
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> grid[i][j];
        }
    }
    // cout << grid[2][2] << endl;
    dfs(2, 2);
    v[2][2] = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            ans += v[i][j];
        }
    }
    cout << ans << endl;
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