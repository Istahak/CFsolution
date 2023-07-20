#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 2e5 + 5;
vector<int> divisor[N];
void init()
{
    for (int i = 1; i < N; i++)
    {
        for (int j = i; j < N; j += i)
        {
            divisor[j].push_back(i);
        }
    }
}
vector<int> adj[N];
int ans[N], dcnt[N], a[N], n;
void dfs(int v, int p, int d)
{
    for (auto di : divisor[a[v]])
        dcnt[di]++;
    for (auto di : divisor[a[v]])
    {
        if ((dcnt[di]) >= (d))
            ans[v] = max(ans[v], di);
    }
    for (auto di : divisor[a[p]])
    {
        if ((dcnt[di]) >= (d))
            ans[v] = max(ans[v], di);
    }
    for (auto u : adj[v])
    {
        if (u == p)
            continue;
        dfs(u, v, d + 1);
    }
    for (auto di : divisor[a[v]])
        dcnt[di]--;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ans[1] = a[1];
    for (auto di : divisor[a[1]])
        dcnt[di]++;
    for (auto u : adj[1])
    {
        dfs(u, 1, 1);
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}