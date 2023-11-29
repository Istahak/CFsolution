#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif
const int N = 303, bb = 19, inf = 1e9;
int n, m, moves;
array<int, 2> st, en;
vector<array<int, 2>> candy;
char grid[N][N];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
bool isvalid(int x, int y)
{
    if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == '#')
        return false;
    return true;
}
void solve()
{
    cin >> n >> m >> moves;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'S')
            {
                auto &[x, y] = st;
                x = i, y = j;
            }
            if (grid[i][j] == 'G')
            {
                auto &[x, y] = en;
                x = i, y = j;
            }
            if (grid[i][j] == 'o')
            {
                candy.push_back({i, j});
            }
        }
    }
    auto bfs = [&](array<int, 2> start)
    {
        vector<vector<int>> reach(n, vector<int>(m, inf));
        vector<vector<int>> vis(n, vector<int>(m, 0));

        reach[start[0]][start[1]] = 0;
        queue<array<int, 2>> q;

        q.push(start);
        while (!q.empty())
        {
            auto [vx, vy] = q.front();
            q.pop();
            if (vis[vx][vy])
                continue;
            vis[vx][vy] = 1;
            for (int i = 0; i < 4; i++)
            {
                int newx = vx + dx[i];
                int newy = vy + dy[i];
                if (isvalid(newx, newy) and !vis[newx][newy])
                {
                    reach[newx][newy] = reach[vx][vy] + 1;
                    q.push({newx, newy});
                }
            }
        }
        return reach;
    };
    auto dis = bfs(st);
    if (dis[en[0]][en[1]] > moves)
    {
        cout << -1 << "\n";
        return;
    }
    int nc = candy.size();
    vector<vector<int>> dp(1 << nc, vector<int>(nc, inf));
    vector<vector<vector<int>>> state(nc, vector<vector<int>>(n, vector<int>(m)));
    for (int i = 0; i < nc; i++)
    {
        state[i] = bfs(candy[i]);
    }
    for (int i = 0; i < (1 << nc); i++)
    {
        for (int j = 0; j < nc; j++)
        {
            if (i & (1 << j))
            {
                int mask = i - (1 << j);
                if (!mask)
                {
                    dp[i][j] = dis[candy[j][0]][candy[j][1]];
                }
                else
                {
                    for (int k = 0; k < nc; k++)
                    {
                        if (mask & (1 << k))
                        {
                            dp[i][j] = min(dp[i][j], dp[mask][k] + state[k][candy[j][0]][candy[j][1]]);
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < (1 << nc); i++)
    {
        for (int j = 0; j < nc; j++)
        {
            if (i & (1LL << j))
            {
                int c = dp[i][j] + state[j][en[0]][en[1]];
                if (c <= moves)
                    ans = max(ans, (int)__builtin_popcount(i));
            }
        }
    }
    cout << ans << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case " << cs << ": ";
        solve();
    }
    return 0;
}