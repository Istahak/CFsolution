#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
const int N = 1e5 + 6;
vector<int> g[N], par(N), dis(N);
vector<bool> vis(N);
queue<int> q;
int n, m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    q.push(1);
    vis[1] = true;
    while (!q.empty())
    {
        int vertex = q.front();
        q.pop();
        for (auto child : g[vertex])
        {
            if (!vis[child])
            {
                dis[child] = dis[vertex] + 1;
                vis[child] = true;
                par[child] = vertex;
                //cout<<child<<' '<<vertex<<endl;
                q.push(child);
            }
        }
    }

    if (!vis[n])
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    int u = n;
    int level = dis[n];
    //cout<<level<<endl;
    vector<int> ans(level + 1);
    for (int i = level; i >= 0; i--)
    {
        ans[i] = u;
        u = par[u];
    }

    cout << ans.size() << endl;
    for (auto i : ans)
        cout << i << ' ';
    cout << endl;

    return 0;
}
