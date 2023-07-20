#include <bits/stdc++.h>
#define ll long long int
using namespace std;
vector<int> adj[30];
int vis[30], ok;
stack<int> ans;
void dfs(int v)
{
    vis[v] = 1;
    for (auto u : adj[v])
    {

        if (!vis[u] and !ok)
            dfs(u);
        else if (vis[u] == 1)
        {
            ok = true;
        }
    }
    vis[v] = 2;
    ans.emplace(v);
}
bool addedge(string a, string b)
{
    int sza = a.size(), szb = b.size();
    for (int i = 0; i < min(sza, szb); i++)
    {
        if (a[i] == b[i])
            continue;
        else
        {
            adj[a[i] - 'a'].push_back(b[i] - 'a');
            return false;
        }
    }
    if (sza > szb)
        return true;
    return false;
}
void solve()
{
    int n;
    cin >> n;
    vector<string> v(n);
    for (auto &x : v)
        cin >> x;
    for (int i = 1; i < n; i++)
    {
        if (addedge(v[i - 1], v[i]))
        {
            cout << "Impossible" << endl;
            return;
        }
    }
    for (int i = 0; i <= 25; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
        if (ok)
        {
            cout << "Impossible" << endl;
            return;
        }
    }

    while (!ans.empty())
    {
        cout << char(ans.top() + 'a');
        ans.pop();
    }
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}