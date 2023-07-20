#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 3000 + 10;
int M = 1e9;
vector<int> adj[N];
set<tuple<int, int, int>> check;
int dis[N][N];
int par[N][N];
void bfs(int x, int y)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            dis[i][j] = M;
    queue<pair<int, int>> q;
    dis[x][y] = 0;
    q.push({x, y});
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int cur = p.first;
        int pre = p.second;
        for (auto nxt : adj[cur])
        {
            if (check.count({pre, cur, nxt}))
                continue;
            if (dis[nxt][cur] != M)
                continue;
            dis[nxt][cur] = dis[cur][pre] + 1;
            par[nxt][cur] = pre;
            q.push({nxt, cur});
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < k; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        check.insert({x, y, z});
    }
    bfs(1, 1);
    int seclast = -1, mi = M;
    for (int i = 1; i <= n; i++)
    {
        if (dis[n][i] < mi)
        {
            seclast = i;
            mi = dis[n][i];
        }
    }
    if (seclast == -1)
    {
        cout << seclast << endl;
        return 0;
    }
    cout << mi << endl;
    vector<int> path;
    int cur = n;
    int pre = seclast;
    while (pre != 1)
    {
        path.push_back(cur);
        int tem = par[cur][pre];
        cur = pre;
        pre = tem;
    }
    path.push_back(cur);
    path.push_back(pre);
    reverse(path.begin(), path.end());
    for (auto ans : path)
        cout << ans << ' ';
    cout << endl;

    return 0;
}