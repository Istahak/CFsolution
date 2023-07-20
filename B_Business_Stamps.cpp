#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 105;
int n, m, rh, ch, rw, cw;
int arr[N][N];
int vis[N][N];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
bool dfs(int x, int y, int i)
{
    if (x > n || x <= 0 || y > m || y <= 0)
        return false;
    if (vis[x][y])
        return false;
    vis[x][y] = 1;
    if (!(i & (1 << (arr[x][y] - 1))))
        return false;
    if (x == rw && y == cw)
        return true;
    bool ans = false;
    for (int j = 0; j < 4; j++)
    {
        ans |= dfs(x + dx[j], y + dy[j], i);
    }

    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    cin >> rh >> ch;
    cin >> rw >> cw;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> arr[i][j];

    int ans = INT_MAX;
    for (int i = 1; i <= (1 << 10); i++)
    {
        memset(vis, 0, sizeof(vis));
        if (dfs(rh, ch, i))
        {
            int cur_ans = __builtin_popcountl(i);
            ans = min(ans, cur_ans);
        }
    }

    cout << ans << endl;

    return 0;
}