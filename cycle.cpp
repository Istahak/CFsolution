#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
const int N = 1e5 + 6;
vector<int> g[N], store, ans;
vector<bool> vis(N);
vector<int> par(N);
int start = -1, en = -1;

void DFS(int vertex, int parent)
{
    vis[vertex] = true;
    par[vertex] = parent;
    for (auto child : g[vertex])
    {
        if (child == parent)
            continue;
        if (vis[child])
        {
            start = child;
            en = vertex;
            return;
        }
        DFS(child, vertex);
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {

        if (!vis[i])
        {
            DFS(i, 0);
        }
        if (start != -1 && en != -1)
            break;
    }
    if (start == -1 && en == -1)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    cout<<start<<' '<<en<<endl;
    vector<int> ans;
    ans.push_back(en);
    while (start != en)
    {
        ans.push_back(start);
        start = par[start];
    }
    ans.push_back(en);

    cout << ans.size() << endl;
    for (auto i : ans)
        cout << i << ' ';
    cout << endl;

    return 0;
}
