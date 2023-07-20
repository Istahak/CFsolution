#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 3e5 + 20;
const int M = 3e5 + 5;
vector<int> divisor[N];
void init()
{
    for (int i = 1; i < N; i++)
    {
        for (int j = i; j < N; j += i)
        {
            divisor[j].push_back(i);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    int n;
    cin >> n;

    vector<vector<int>> adj(2 * N);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        for (auto d : divisor[x])
        {
            if (d == 1)
                continue;
            adj[d + M].push_back(i);
            adj[i].push_back(d + M);
        }
    }
    int s, t;
    cin >> s >> t;
    s--, t--;
    int par[2 * N];
    int dist[2 * N];
    for (int i = 0; i < 2 * N; i++)
        par[i] = -1, dist[i] = 1e9;
    queue<int> q;
    q.emplace(s);
    dist[s] = 0;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (auto u : adj[v])
        {
            if (dist[u] == 1e9)
            {
                dist[u] = dist[v] + 1;
                par[u] = v;
                q.emplace(u);
            }
        }
    }
    if (dist[t] == 1e9)
    {
        cout << -1 << endl;
        return 0;
    }
    vector<int> ans;
    for (int cur = t; cur != s; cur = par[cur])
    {
        if (cur < M)
            ans.push_back(cur);
    }
    ans.push_back(s);
    reverse(ans.begin(), ans.end());

    cout << (int)ans.size() << '\n';
    for (int u : ans)
    {
        cout << 1 + u << " ";
    }
    cout << '\n';
    return 0;
}