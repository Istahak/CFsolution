#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n, m;
int fa[N];
vector<pair<int, int>> G[N];
int w[N];
bool vis[N];
bool flag = false;

int find(int x)
{
    if (fa[x] == x)
        return x;
    int r = find(fa[x]);
    w[x] ^= w[fa[x]];
    return fa[x] = r;
}

void dfs(int u)
{
    vis[u] = true;
    for (auto [v, k] : G[u])
    {

        if (vis[v])
        {
            if (w[v] != w[u] ^ k)
            {
                flag = true;
                return;
            }
        }
        else
        {
            w[v] = w[u] ^ k;
            dfs(v);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
        int faa = find(a), fab = find(b);
        if (faa == fab)
        {
            if (w[a] != w[b] ^ c)
            {
                cout << -1 << endl;
                return 0;
            }
        }
        else
        {
            fa[faa] = fab;
            w[faa] = w[b] ^ w[a] ^ c;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
            if (flag)
                break;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += w[i];
    if (flag)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}
