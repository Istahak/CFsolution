#include <bits/stdc++.h>
#define ll long long int
#define lll __int128_t
using namespace std;
void solve()
{
    ll n, c;
    cin >> n >> c;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    ll ans = -1;
    ll l = 0, r = sqrt(c);
    while (l <= r)
    {
        lll cur = 0;
        lll mid = (l + r) / 2;
        for (int i = 0; i < n; i++)
        {
            cur = cur + (v[i] + mid) * (v[i] + mid);
        }
        if (cur <= c)
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }

    cout << ans/2 << endl;
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