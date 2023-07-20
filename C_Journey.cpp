#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e5 + 1;
vector<int> adj[N + 1];
int level[N];
double pro[N];
void dfs(int vertex, int parent)
{
    int x = adj[vertex].size() - 1;
    if (vertex == 1)
        x++;
    if (x == 0)
        return;
    for (auto child : adj[vertex])
    {
        if (child == parent)
            continue;
        level[child] = level[vertex] + 1;
        pro[child] = (pro[vertex] * (1.0)) / ((double)x);
        dfs(child, vertex);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    //vector<int> adj[n + 1];
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    pro[1]=1.0;
    dfs(1,-1);
    double ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int d = adj[i].size();
        if (d == 1)
        {
            ans += (pro[i] * level[i]*(1.0));
        }
        //cout<<level[i]<<' '<<pro[i]<<endl;
    }
    printf("%0.15lf\n", ans);

    return 0;
}