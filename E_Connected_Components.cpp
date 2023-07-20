#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 200003;
set<int> adj[N], node;
vector<int> ans;
vector<bool> vis(N);
int n, m;
void bfs(int x)
{
    vis[x] = true;
    node.erase(x);
    int cur = 1;
    queue<int> q;
    q.push(x);
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        vector<int> v;
        for (auto &node : node)
        {
            if (!adj[par].count(node))
            {
                vis[node] = true;
                cur++;
                v.push_back(node);
                q.push(node);
            }
        }
        for (auto &x : v)
            node.erase(x);
    }
    ans.push_back(cur);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        node.insert(i);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        else
            bfs(i);
    }
    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for (auto ans : ans)
        cout << ans << ' ';
    cout << endl;
    return 0;
}