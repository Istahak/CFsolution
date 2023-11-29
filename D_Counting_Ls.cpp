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
    vector<string> v(n);
    for (auto &x : v)
        cin >> x;
    vector<ll> r(n), c(n);
    for (int i = 0; i < n; i++)
    {
        int cc = 0;
        for (int j = 0; j < n; j++)
        {
            if (v[i][j] == 'o')
                cc++;
        }
        r[i] = cc;
    }
    for (int i = 0; i < n; i++)
    {
        int cc = 0;
        for (int j = 0; j < n; j++)
        {
            if (v[j][i] == 'o')
                cc++;
        }
        c[i] = cc;
    }
    // debug(), dbg(r), dbg(c);
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            if (v[i][j] == 'o')
            {
                ans += (r[i] - 1) * (c[j] - 1);
            }
        }
    }
    cout << ans << '\n';
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