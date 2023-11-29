#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif
pair<int, int> f(int val)
{

    int cc = 0;
    while (val % 2 == 0)
    {
        val /= 2;
        cc++;
    }

    return {cc, val};
}
ll ff(ll n)
{
    n = n * (n - 1);
    n /= 2;
    return n;
}
void solve()
{
    ll n;
    cin >> n;
    map<pair<int, int>, ll> cnt;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        auto [pp, vv] = f(x);
        cnt[{x - pp, vv}]++;
    }
    ll ans = 0;
    for (auto [x, y] : cnt)
    {
        ans += ff(y);
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