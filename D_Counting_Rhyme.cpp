#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll f(ll n)
{
    n = n * (n - 1);
    n >>= 1;
    return n;
}
void solve()
{
    ll n;
    cin >> n;
    vector<ll> cnt(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
    vector<ll> nop(n + 1);
    for (int i = n; i > 0; i--)
    {
        ll cur = 0;
        for (int j = i; j <= n; j += i)
        {
            cur += cnt[j];
            nop[i] -= nop[j];
        }
        nop[i] += f(cur);
    }
    // for (int i = 1; i <= n; i++)
    //     cout << nop[i] << ' ';
    // cout << '\n';
    ll ans = f(n);
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i])
        {
            for (int j = i; j <= n; j += i)
            {
                ans -= nop[j];
                nop[j] = 0;
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
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}