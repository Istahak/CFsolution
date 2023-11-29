#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;
    int mx = 0;
    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        mx = max(mx, v[i] - cur);
        cur = v[i];
    }
    mx = max(mx, 2 * (x - v.back()));
    cout << mx << '\n';
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