#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    ll k, n, a, b;
    cin >> k >> n >> a >> b;
    ll ans = -1;
    ll l = 0, r = n;
    auto ispossible = [&](ll mid)
    {
        ll cur = mid * a;
        if (cur >= k)
            return false;
        cur += (n - mid) * b;
        return cur < k;
    };
    while (l <= r)
    {
        ll mid = l + (r - l) / 2;
    
        if (ispossible(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
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