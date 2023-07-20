#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;
    sort(v.begin(), v.end());
    ll ans = -1;
    ll l = v[n / 2], r = l + k;
    auto ispossible = [&](ll mid)
    {
        ll need = 0;
        for (int i = n / 2; i < n; i++)
        {
            if (v[i] < mid)
                need += (mid - v[i]);
        }
        return need <= k;
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
    // cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}