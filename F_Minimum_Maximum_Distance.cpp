#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    set<int> col;
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        x--;
        col.insert(x);
    }
    vector<int> adj[n];
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto bfs = [&](int source)
    {
        vector<int> d(n, -1);
        queue<int> q;
        q.push(source);
        d[source] = 0;
        while (!q.empty())
        {
            auto v = q.front();
            q.pop();
            for (auto u : adj[v])
            {
                if (d[u] == -1)
                {
                    d[u] = d[v] + 1;
                    q.push(u);
                }
            }
        }
        return d;
    };
    auto disf1 = bfs(0);
    int first = max_element(disf1.begin(), disf1.end()) - disf1.begin();
    int f1 = 0, fn = 0;
    for (int i = 0; i < n; i++)
    {
        if (disf1[i] > f1 and col.count(i))
        {
            fn = i;
            f1 = disf1[i];
        }
    }
    auto disf2 = bfs(fn);
    int second = max_element(disf2.begin(), disf2.end()) - disf2.begin();
    auto disf3 = bfs(second);

    int f2 = 0, fnn = 0;
    for (int i = 0; i < n; i++)
    {
        if (disf2[i] >= f2 and col.count(i))
        {
            fnn = i;
            f2 = disf2[i];
        }
    }
    function<int(int, int, int)> dfs = [&](int u, int v, int p)
    {
        if (u == v)
            return 0;
        int ans = 1e9;
        for (auto c : adj[u])
        {
            if (c == p)
                continue;
            ans = min(ans, 1 + dfs(c, v, u));
        }
        return ans;
    };
    int dia = dfs(fn, fnn, -1);

    cout << (dia + 1) / 2 << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}