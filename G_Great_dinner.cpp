#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int M = 1e9 + 7, N = 1e5 + 10;
ll fact[N + 10], invfact[N + 10];
ll bigmod(ll a, ll b)
{
    a %= M;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % M;
        a = a * a % M;
        b >>= 1;
    }
    return res;
}
void factorialcul()
{
    fact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = ((fact[i - 1] % M) * (i % M)) % M;
    }
    invfact[N - 1] = bigmod(fact[N - 1], M - 2);
    for (int i = N - 2; i >= 0; --i)
    {
        invfact[i] = ((invfact[i + 1] % M) * (i + 1)) % M;
    }
}
ll ncr(ll n, ll r)
{
    if (r > n)
        return 0ll;
    ll res = fact[n] % M;
    res = res * (invfact[n - r] % M);
    res %= M;
    res = res * (invfact[r] % M);
    res %= M;
    return res;
}
vector<int> adj[N];
int vis[N];
int cc = 0;
void dfs(int v)
{
    vis[v] = 1;
    cc++;
    for (auto u : adj[v])
    {
        if (vis[u])
            continue;
        dfs(u);
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
    }
    ll ans = fact[n];
    for (int i = 1; i <= m; i++)
    {

        ans = ans * invfact[2];
        ans %= M;
    }
    cout << ans % M << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    factorialcul();
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}