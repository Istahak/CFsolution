#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll f(ll x)
{
    ll tem = x * (x + 1);
    tem /= 2;
    return tem;
}
void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    ll ans = 0;
    for (int b = 0; b <= 32; b++)
    {
        vector<ll> bit(n + 1);
        for (int i = 1; i <= n; i++)
        {
            bit[i] = (((1 << b) & v[i]) ? 1 : 0);
        }
        vector<ll> odd(n + 1, 0);
        vector<ll> even(n + 1, 0);
        // int val = 0;
        vector<ll> cnt(2, 0);
        cnt[0] = 1;
        ll cur = 0, val = 0;
        for (int i = 1; i <= n; i++)
        {
            val += bit[i];
            val %= 2;
            cnt[val]++;
            if (val)
                cur += (cnt[1] * i);
        }
        if (cur)
        {
            ans += (1 << b) * cur;
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
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}