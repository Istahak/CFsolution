#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
const int N = 1e5 + 6;
vector<pair<int, int>> g[N];
map<int, int> mp;
bool flag = false;
int n, a, b;
void dfsa(int vertex, int parent, int value)
{
    if (vertex == b)
        return;
    mp[value] = 1;
    for (auto [x, y] : g[vertex])
    {
        if (x == parent)
            continue;
        dfsa(x, vertex, value ^ y);
    }
}
void dfsb(int vertex, int parent, int value)
{

    if (mp[value] && vertex != b)
        flag = true;

    for (auto [x, y] : g[vertex])
    {
        if (x == parent)
            continue;
        dfsb(x, vertex, value ^ y);
    }
}
void solve()
{
    cin >> n >> a >> b;
    for (int i = 0; i <= n + 1; i++)
    {
        g[i].clear();
    }
    mp.clear();
    flag = false;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, x;
        cin >> u >> v >> x;
        g[u].push_back({v, x});
        g[v].push_back({u, x});
    }
    dfsa(a, -1, 0);
    dfsb(b, -1, 0);

    cout << (flag ? "YES" : "NO") << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    cin >> t;
    while (t--)
    {

        solve();
    }

    return 0;
}