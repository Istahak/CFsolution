#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int n, k;
const int N = 1e6 + 10;
vector<int> adj[N + 1];
ll cnt = 0, k_par = 0;
int par[N];
void dfs(int vertex, int parent)
{
    par[vertex] = parent;
    if (vertex == k)
    {
        k_par = parent;
    }
    for (auto child : adj[vertex])
    {
        if (child == parent)
            continue;
        dfs(child, vertex);
    }
}

void dfs1(int vertex, int parent)
{

    if (vertex == k_par)
        return;
    for (auto child : adj[vertex])
    {
        if (child == parent)
            continue;
        cnt++; 
        dfs1(child, vertex);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    par[1] = -1;
    dfs(1, -1);
    dfs1(1, 0);
    int flag = par[k_par], cur = 0;
    while (flag != -1)
    {
        flag = par[flag];
        cur++;
    }

    cout << 2 * cnt - cur + 1 << endl;

    return 0;
}