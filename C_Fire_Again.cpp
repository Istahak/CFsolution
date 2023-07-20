#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 2010;
int grid[N][N];
int dist[N][N];
int n, m, k;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
bool isValid(int row, int col)
{
    if (row <= 0 || col <= 0 || row > n || col > m)
        return false;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m >> k;
    queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dist[i][j] = 1e9;
        }
    }
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        dist[x][y] = 0;
        q.emplace(x, y);
    }
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];

            if (isValid(xx, yy) and ((1 + dist[x][y] < dist[xx][yy])))
            {
                dist[xx][yy] = 1 + dist[x][y];
                // cout << xx << ' ' << yy << ' ' << dist[xx][yy] << endl;
                q.emplace(xx, yy);
            }
        }
    }
    pair<int, int> ans;
    auto &[x, y] = ans;
    int curdist = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (dist[i][j] >= curdist)
            {
                curdist = dist[i][j];
                x = i, y = j;
            }
        }
    }
    cout << x << ' ' << y << endl;

    return 0;
}