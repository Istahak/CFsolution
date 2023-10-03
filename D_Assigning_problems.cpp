#include <bits/stdc++.h>
#define ll long long int
#define lll __int128_t
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<ll> c(n + 2);
    vector<ll> p(n + 2);
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    auto ok = [&](lll m)
    {
        lll exrta = 0;
        for (int i = n; i >= 1; i--)
        {
            lll need = (c[i] * m);
            need += exrta;
            if (need <= p[i])
            {
                exrta = 0;
            }
            else
            {
                exrta = need - p[i];
            }
        }

        return exrta == 0;
    };

    lll l = 0,
       r = 1e18;
    ll ans = 0;
    while (l <= r)
    {
        lll m = l + (r - l) / 2;

        if (ok(m))
        {
            ans = m;
            l = m + 1;
        }
        else
        {
            r = m - 1;
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