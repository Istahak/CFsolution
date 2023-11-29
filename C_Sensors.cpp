#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int n, m;
char grid[1001][1001];
int vis[1001][1001];
/*----------------------Graph Moves----------------*/
// const int fx[]={+1,-1,+0,+0};
// const int fy[]={+0,+0,+1,-1};
const int fx[] = {+0, +0, +1, -1, -1, +1, -1, +1}; // Kings Move
const int fy[] = {-1, +1, +0, +0, +1, +1, -1, -1}; // Kings Move
// const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
// const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/
bool isvalid(int x, int y)
{
    if (x < 1 || y < 1 || x > n || y > m)
        return false;
    if (grid[x][y] == '.' or vis[x][y])
        return false;
    return true;
}
void dfs(int i, int j)
{
    vis[i][j] = 1;
    for (int cur = 0; cur < 8; cur++)
    {
        int x = i + fx[cur];
        int y = j + fy[cur];
        if (isvalid(x, y))
        {
            dfs(x, y);
        }
    }
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
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (grid[i][j] == '#' and !vis[i][j])
            {
                ans++;
                dfs(i, j);
            }
        }
    }
    cout << ans << '\n';
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