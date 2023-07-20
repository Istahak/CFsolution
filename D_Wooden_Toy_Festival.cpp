#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;
    sort(v.begin(), v.end());
    ll ans = -1;
    ll l = 0, r = 1e9;
    auto ispossible = [&](ll mid)
    {
        vector<pair<ll, ll>> ff(n);
        for (int i = 0; i < n; i++)
        {
            ff[i] = {max(1LL, v[i] - mid), v[i] + mid};
        }
        int interval = 1;
        for (int i = 0; i < n - 1; i++)
        {
            auto &[x, y] = ff[i + 1];
            auto &[p, q] = ff[i];
            if (x <= q)
            {
                x = max(p, x);
                y = q;
            }
            else
                interval++;
        }
        return interval <= 3;
    };
    while (l <= r)
    {
        ll mid = l + (r - l) / 2;

        if (ispossible(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }

    cout << ans << endl;
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