#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;

    ll ans = LLONG_MIN;
    ll cur = 0;
    int i = 0;
    while (i < n)
    {
        int j = i + 1;
        ans = max(ans, v[i]);
        ll p = v[i];
        ll cur = p;
        while (j < n and abs(p) % 2 != abs(v[j]) % 2)
        {
            if (cur < 0)
                break;
            ans = max(ans, cur);
            cur += v[j];
            p = v[j];
            j++;
        }
        ans = max(ans, cur);
        i = j;
    }
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