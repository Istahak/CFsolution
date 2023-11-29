#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<set<int>> v(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v[i].insert(x);
    }
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (v[a].size() > v[b].size())
        {
            swap(v[a], v[b]);
        }
        for (auto x : v[a])
            v[b].insert(x);
        v[a].clear();
        cout << v[b].size() << '\n';
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case " << cs << ": ";
        solve();
    }
    return 0;
}