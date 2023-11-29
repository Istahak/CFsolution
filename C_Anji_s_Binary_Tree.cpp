#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif
const int N = 3e5 + 10;
string s;
pair<int, int> adj[N];
int f(int v)
{
    auto &[x, y] = adj[v];
    if (x == 0 and y == 0)
        return 0;

    int left = INT_MAX, right = INT_MAX;
    if (x)
    {
        if (s[v] == 'L')
        {
            left = f(x);
        }
        else
        {
            left = 1 + f(x);
        }
    }
    if (y)
    {
        if (s[v] == 'R')
        {
            right = f(y);
        }
        else
        {
            right = 1 + f(y);
        }
    }
    return min(left, right);
}
void solve()
{
    int n;
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        
        int u, v;
        cin >> u >> v;
        if (u)
            u--;
        if (v)
            v--;
        auto &[x, y] = adj[i];
        x = u, y = v;
    }

    cout << f(0) << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case " << cs << ": ";
        solve();
    }
    return 0;
}