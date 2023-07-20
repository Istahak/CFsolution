#include <bits/stdc++.h>
#define ll long long int
using namespace std;
char grid[52][52];
int vis[52][52];
int n, m;
bool ok;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
bool isvalid(int x, int y, int px, int py, char cur)
{
    if (x < 1 || y < 1 || x > n || y > m)
        return false;

    if (vis[x][y])
        return false;
    if (grid[x][y] != cur)
        return false;

    return true;
}
bool isv(int x, int y, int px, int py, char cur)
{
    if (x < 1 || y < 1 || x > n || y > m)
        return false;
    if (vis[x][y] and (px != x or py != y) and grid[x][y] == cur)
    {
        cout << x << ' ' << y << " " << px << " " << py << endl;
        return true;
    }
    else
        return false;
}
bool dfs(int x, int y, int px, int py, char cur)
{
    
    vis[x][y] = 1;
    bool ok = false;
    for (int i = 0; i < 4; i++)
    {

        if (isvalid(x + dx[i], y + dy[i], x, y, cur))
        {
            if (dfs(x + dx[i], y + dy[i], x, y, cur))
            {

                ok = true;
                break;
            }
        }
        else if (isv(x + dx[i], y + dy[i], x, y, cur))
        {

            ok = true;
            break;
        }
        if(ok) break;
    }
    return ok;
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> grid[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (!vis[i][j])
            {
                if (dfs(i, j, -1, -1, grid[i][j]))
                {
                    cout << "Yes" << endl;
                    return;
                }
            }
        }
    }
    cout << "No" << endl;
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