#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int mar, var;
    cin >> mar >> var;
    vector<int> adj[n + 1];
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> vis(n + 1, 0);
    vector<int> par(n + 1);
    int cycle_start, cycle_end;

    function<void(int, int)> dfs = [&](int v, int p)
    {
        vis[v] = 1;
        for (int u : adj[v])
        {
            if (vis[u])
            {
                if (u == p)
                    continue;
                else
                {
                    cycle_start = u;
                    cycle_end = v;
                    continue;
                }
            }
            else
            {
                par[u] = v;
                dfs(u, v);
            }
        }
    };
    int rt = -1;
    for (int i = 1; i <= n; i++)
    {
        if (adj[i].size() == 1)
        {
            rt = i;
            break;
        }
    }
    if (rt == -1)
    {
        if (mar == var)
        {
            cout << "NO" << '\n';
        }
        else
        {
            cout << "YES" << '\n';
        }
        return;
    }
    dfs(rt, 0);
    // for (int i = 1; i <= n; i++)
    //     cout << i << ' ' << par[i] << '\n';
    // // cout << cy1 << ' ' << cy2 << '\n';
    // cout << cycle_end << ' ' << cycle_start << '\n';

    vector<int> cy;
    cy.push_back(cycle_start);
    int cur = cycle_start;
    while (cur != cycle_end)
    {
        cur = par[cur];
        cy.push_back(cur);
    }
    cy.push_back(cur);
    // for (auto x : cy)
    //     cout << x << ' ';
    // cout << '\n';
    // cout<<par[cur]<<' '<<par[par[par[par[cur]]]]<<'\n';
    auto bfs = [&](int s)
    {
        vector<int> d(n + 1, -1);
        d[s] = 0;
        queue<int> q;
        q.push(s);
        vector<int> vvs(n + 1, 0);
        vvs[s] = 1;
        while (!q.empty())
        {
            auto v = q.front();
            q.pop();
            for (auto u : adj[v])
            {
                if (d[u] == -1)
                {
                    d[u] = d[v] + 1;
                    q.push(u);
                }
            }
        }
        return d;
    };
    auto mardis = bfs(mar);
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << i << ' ' << mardis[i] << '\n';
    // }
    auto vardis = bfs(var);
    int node = -1;
    int dis = 1e9;
    for (auto x : cy)
    {
        if (vardis[x] < dis)
        {
            dis = vardis[x];
            node = x;
        }
    }
    if (dis < mardis[node])
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
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