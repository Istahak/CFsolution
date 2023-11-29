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
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    auto divisor = [&](int64_t n)
    {
        vector<int64_t> div;
        for (int64_t i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                div.push_back(i);
                if (n / i == i)
                    continue;
                div.push_back(n / i);
            }
        }
        sort(div.begin(), div.end());
        return div;
    };
    auto d = divisor(n);
    ll ans = 0;
    for (auto p : d)
    {
        ll mx = -1, mi = LLONG_MAX;
        ll cur = 0;
        for (int i = 0; i < n; i++)
        {
            cur += v[i];
            if ((i + 1) % p == 0)
            {
                mx = max(cur, mx), mi = min(cur, mi);
                cur = 0;
            }
        }
        ans = max(ans, abs(mx - mi));
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