#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 2e5 + 10;
int parent[N + 1];
ll sz[N + 1];
ll ans = 0;
ll cal(ll n)
{
    ll res = (n * (n - 1)) / 2;
    return res;
}
void make(int v)
{
    parent[v] = v;
    sz[v] = 1;
}
int find(int v)
{
    if (parent[v] == v)
        return v;
    else
        return parent[v] = find(parent[v]);
}
void marge(int u, int v)
{
    ll a = find(u);
    ll b = find(v);
    if (a != b)
    {
        parent[b] = a;
        ll pre = sz[a];
        sz[a] += sz[b];
        ans += (cal(sz[a]) - cal(sz[b]) - cal(pre));
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> adj(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[i].first = w;
        adj[i].second.first = u;
        adj[i].second.second = v;
    }
    sort(adj.begin(), adj.end());
    vector<pair<int, int>> query(m);
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        query[i].first = x;
        query[i].second = i;
    }
    sort(query.begin(), query.end());
    for (int i = 1; i <= n; i++)
    {
        make(i);
    }
    vector<ll> anss(m);
    int j = 0;
    for (int i = 0; i < m; i++)
    {
        {
            for (; j < n - 1; j++)
            {
                if (adj[j].first <= query[i].first)
                {
                    marge(adj[j].second.first, adj[j].second.second);
                }
                else
                    break;
            }
            anss[query[i].second] = ans;
        }
    }
    for (auto ans : anss)
        cout << ans << ' ';
    cout << endl;
    return 0;
}