#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n + 1), ans(n + 1, -1);
    vector<int> adj[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        if ((i - v[i]) >= 1)
            adj[i - v[i]].push_back(i);
        if ((i + v[i]) <= n)
            adj[i + v[i]].push_back(i);
    }

    queue<int> q;
    vector<int> dis(n + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        if (v[i] & 1)
        {
            q.push(i);
            dis[i] = 0;
        }
    }
    while (!q.empty())
    {
        auto vr = q.front();
        q.pop();
        for (auto u : adj[vr])
        {
            if (dis[u] == -1)
            {
                dis[u] = dis[vr] + 1;

                q.push(u);
            }
        }
    }
    vector<int> diss(n + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        if (~v[i] & 1)
        {
            ans[i] = dis[i];
            q.push(i);
            diss[i] = 0;
        }
    }
    while (!q.empty())
    {
        auto vr = q.front();
        q.pop();
        for (auto u : adj[vr])
        {
            if (diss[u] == -1)
            {
                diss[u] = diss[vr] + 1;

                q.push(u);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (v[i] & 1)
        {
            ans[i] = diss[i];
        }
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
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