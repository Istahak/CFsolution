#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 2e5 + 10;
vector<int> adj[N + 1], vis(N), curr;
void dfs(int vertex)
{
    curr.push_back(vertex);
    vis[vertex] = true;
    for (auto child : adj[vertex])
    {
        if (vis[child])
            continue;
        dfs(child);
    }
}
void reset(int n)
{
    for (int i = 0; i <= n; i++)
    {
        adj[i].clear();
        vis[i] = false;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        reset(n);
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            adj[x].push_back(i);
        }
        int cyclecom = 0;
        bool ok = false;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i])
                continue;
            curr.clear();
            dfs(i);
            sort(curr.begin(), curr.end());
            for (int i = 0; i < curr.size() - 1; i++)
            {
                if ((curr[i] + 1) == curr[i + 1])
                    ok = true;
            }
            cyclecom += (curr.size() - 1);
        }
        cout << (ok ? --cyclecom : ++cyclecom) << endl;
    }

    return 0;
}