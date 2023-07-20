#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1005;
ll arr[N][N];
bool vis[N][N];
int n, m;
ll cnt;
void dfs(int x, int y)
{
    if (x <= 0 || y <= 0 || x > n || y > m || arr[x][y] == 0 || vis[x][y])
        return;
    cnt += arr[x][y];
    vis[x][y] = true;
    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
            vis[i][j] = 0;
        }
    }
    ll ans = LLONG_MIN;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (arr[i][j] != 0 && !vis[i][j])
            {
                cnt = 0;
                dfs(i, j);
                ans = max(ans, cnt);
            }
        }
    }
    if (ans == LLONG_MIN)
    {
        cout << 0 << endl;
        return;
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}