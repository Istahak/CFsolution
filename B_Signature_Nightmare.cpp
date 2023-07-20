#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    ll l = 0, r = 3 * 1e9;
    ll ans = -1;
    while (l <= r)
    {
        ll mid = l + (r - l) / 2;
        bool ok = true;
        ll cur = k;
        for (int i = 0; i < n; i++)
        {
            ll need = b[i] - a[i] * mid;
            if (need >= 0)
                continue;
            need = -need;
            if (cur - need < 0)
            {
                ok = false;
                break;
            }
            cur -= need;
        }
        if (ok)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << ans << endl;
}
int main()
{

    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {

        solve();
    }

    return 0;
}