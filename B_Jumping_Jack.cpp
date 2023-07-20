#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    ll n;
    cin >> n;
    if (n < 0)
        n = -n;
    ll l = 0, r = 1e9 + 10;
    ll ans = -1;
    while (l <= r)
    {
        ll mid = l + (r - l) / 2;
        ll ok = (mid * (mid + 1)) / 2;
        if (ok >= n)
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    for (ll i = ans;; i++)
    {
        ll ok = (i * (i + 1)) / 2;
        ok -= n;
        if (ok % 2 == 0)
        {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    // cin >> t;
    while (t--)
    {

        solve();
    }

    return 0;
}