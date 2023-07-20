#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int MAX_N = 100005;
vector<int> adj[MAX_N];
int lvl[MAX_N];//level of each node
int dp[MAX_N];//extra edge of this node
bool bridge;//if extra node ==0,then bridge
int n, m;
vector<pair<int, int>> ans;
void dfs(int vertex, int parent)
{
    lvl[vertex] = lvl[parent] + 1;

    for (int nxt : adj[vertex])
    {
        if (lvl[nxt] != 0)
        {
            if (nxt != parent)
            {
                if (lvl[nxt] > lvl[vertex])
                {
                    dp[vertex]--;
                    ans.push_back(make_pair(nxt, vertex));
                }
                else if (lvl[nxt] < lvl[vertex])
                {
                    dp[vertex]++;
                }
            }
        }
        else
        {
            dfs(nxt, vertex);
            ans.push_back(make_pair(vertex, nxt));
            dp[vertex] += dp[nxt];
        }
    }

    if (dp[vertex] == 0 && vertex != parent)
    {
        bridge = true;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 1);
    // for (int i = 1; i <= n; i++)
    //     cout << lvl[i] << ' ' << dp[i] << ' ' << i << endl;
    if (!bridge)
    {
        for (auto [x, y] : ans)
            cout << x << ' ' << y << endl;
    }
    else
        cout << 0 << endl;

    return 0;
}