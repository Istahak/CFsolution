#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int INF = INT_MAX;
int n, m, r, c, x, y;
char grid[2005][2005];
bool vis[2005][2005];
int left_dist[2005][2005];
int right_dist[2005][2005];
bool valid(int row, int col)
{
    return (row >= 1 and row <= n and col >= 1 and col <= m and grid[row][col] == '.');
}
void bfs(int x, int y)
{
    left_dist[x][y] = right_dist[x][y] = 0;
    deque<pair<int, int>> q;
    q.push_front({x, y});
    vis[x][y] = true;
    while (!q.empty())
    {
        auto [r, c] = q.front();
        q.pop_front();
        if (valid(r + 1, c) and !vis[r + 1][c])
        {
            q.push_front({r + 1, c});
            vis[r + 1][c] = true;
            left_dist[r + 1][c] = left_dist[r][c];
            right_dist[r + 1][c] = right_dist[r][c];
        }
        if (valid(r - 1, c) and !vis[r - 1][c])
        {
            q.push_front({r - 1, c});
            vis[r - 1][c] = true;
            left_dist[r - 1][c] = left_dist[r][c];
            right_dist[r - 1][c] = right_dist[r][c];
        }

        if (valid(r, c + 1) and (!vis[r][c + 1] or right_dist[r][c] + 1 < right_dist[r][c + 1]))
        {
            q.push_back({r, c + 1});
            vis[r][c + 1] = true;
            left_dist[r][c + 1] = left_dist[r][c];
            right_dist[r][c + 1] = right_dist[r][c] + 1;
        }

        if (valid(r, c - 1) and (!vis[r][c - 1] or left_dist[r][c] + 1 < left_dist[r][c - 1]))
        {
            q.push_back({r, c - 1});
            vis[r][c - 1] = true;
            left_dist[r][c - 1] = left_dist[r][c] + 1;
            right_dist[r][c - 1] = right_dist[r][c];
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> r >> c >> x >> y;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> grid[i][j];
            left_dist[i][j] = right_dist[i][j] = INF;
        }
    }
    bfs(r, c);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (left_dist[i][j] <= x && right_dist[i][j] <= y)
                ans++;
        }
    }
    cout << ans << endl;

    return 0;
}