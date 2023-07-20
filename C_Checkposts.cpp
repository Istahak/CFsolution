#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 3e5 + 9, M = 1000000007;
bool vis[N];
vector<int> g[N], r[N], G[N], vec;
void dfs1(int vertex)
{
    vis[vertex] = 1;
    for (auto child : g[vertex])
        if (!vis[child])
            dfs1(child);
    vec.push_back(vertex);
}
vector<int> comp;
void dfs2(int vertex)
{
    comp.push_back(vertex);
    vis[vertex] = 1;
    for (auto child : r[vertex])
        if (!vis[child])
            dfs2(child);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n;
    vector<int> cost(n);
    for (auto &i : cost)
        cin >> i;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        r[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs1(i);
    reverse(vec.begin(), vec.end());
    memset(vis, 0, sizeof vis);
    vector<vector<int>> store;
    for (auto u : vec)
    {
        if (!vis[u])
        {
            comp.clear();
            dfs2(u);
            store.push_back(comp);
        }
    }
    ll anscost = 0;
    ll answay = 1;
    for (auto cur : store)
    {
        int curmi = INT_MAX;
        for (auto v : cur)
            curmi = min(curmi, cost[v - 1]);
        ll cnt = 0;
        for (auto v : cur)
            if (cost[v - 1] == curmi)
                cnt++;
        anscost += curmi;
        answay *= cnt;
        answay %= M;
    }
    cout << anscost << ' ' << answay << endl;

    return 0;
}