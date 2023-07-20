#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    ll k, sum = 0, mx = LLONG_MIN;
    cin >> n >> k;
    vector<tuple<ll, ll, ll>> v(n);
    for (auto &[x, y, z] : v)
        cin >> x >> y >> z, sum += x, mx = max(mx, x);
    ll ans = -1;
    ll l = (sum + n - 1) / n, r = mx;
    auto ispossible = [&](ll mid)
    {
        vector<tuple<ll, ll, ll>> a, b;
        for (auto [x, y, z] : v)
        {
            if (x > mid)
                b.emplace_back(x, y, z);
            else if (x < mid)
                a.emplace_back(z, x, y);
        }
        sort(b.rbegin(), b.rend());
        sort(a.begin(), a.end());
        int sza = a.size(), szb = b.size();
        int i = 0, j = 0;
        ll need = 0;
        while (i < sza and j < szb)
        {
            auto &[p, q, r] = b[j];
            auto &[u, v, w] = a[i];
            ll cur = min(p - mid, mid - v);
            p -= cur;
            v += cur;
            need += (cur * (u + q));
            if (p == mid)
                j++;
            if (v == mid)
                i++;
        }

        return need <= k;
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
    // cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}