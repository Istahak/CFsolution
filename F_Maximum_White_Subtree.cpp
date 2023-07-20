#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 2e5 + 10;
vector<int> adj[N];
int dp[N];
int val[N];
int ans[N];
int n;
void dfs1(int vertex, int par)
{
    dp[vertex] = val[vertex];
    for (auto child : adj[vertex])
    {
        if (child != par)
        {
            dfs1(child, vertex);
            dp[vertex] += max(0, dp[child]);
        }
    }
}
void dfs2(int vertex, int par)
{
    ans[vertex] = dp[vertex];
    for (auto child : adj[vertex])
    {
        if (child != par)
        {
            int storechild = dp[child];
            int storevertex = dp[vertex];
            dp[vertex] -= max(0, dp[child]);
            dp[child] += max(0, dp[vertex]);
            dfs2(child, vertex);
            dp[child] = storechild;
            dp[vertex] = storevertex;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> val[i];
        if (val[i] == 0)
            val[i] = -1;
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1, 1);
    dfs2(1, 1);
    for (int i = 1; i <= n; i++)
        cout <<ans[i]<<' ';
    cout << endl;

    return 0;
}