#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 2e5 + 6;
vector<int> adj[N + 1], colour(N);
bool vis[N];
void dfs(int vertex)
{
    if (vis[vertex])
        return;
    vis[vertex] = true;
    for (auto child : adj[vertex])
    {
        if (colour[child] == colour[vertex])
        {
            colour[child] = 3;
            continue;
        }
        if (colour[vertex] == 1)
            colour[child] = 2;
        else if (colour[vertex] == 2)
            colour[child] = 1;
        else
            colour[child] = 1;

        dfs(child);
    }
}
void reset(int n)
{
    for (int i = 0; i <= n; i++)
    {
        adj[i].clear();
        vis[i] = false;
        colour[i] = -1;
    }
}
void solve()
{
    int n;
    cin >> n;
    reset(n);
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    if (v[1] != v[n])
    {
        adj[1].push_back(n);
        adj[n].push_back(1);
    }
    for (int i = 1; i < n; i++)
    {
        if (v[i] == v[i + 1])
            continue;
        adj[i + 1].push_back(i);
        adj[i].push_back(i + 1);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            colour[i] = 1;
            dfs(i);
        }
    }
    int ans = 1;
    for (int i = 1; i <= n; i++)
        ans = max(ans, colour[i]);
    cout << ans << endl;
    for (int i = 1; i <= n; i++)
        cout << colour[i] << ' ';
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}