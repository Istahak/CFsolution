#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;
    ll ans = 0;
    ll cur = v[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        ll move = (v[i] + cur - 1) / cur;
        ans += move - 1;
        cur = v[i] / move;
    }
    // debug(), dbg(v);
    cout << ans << '\n';
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