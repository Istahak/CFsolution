#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<ll> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    vector<ll> diff(n + 2, 0);
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        diff[l]++, diff[r + 1]--;
    }
    for (int i = 1; i < n + 2; i++)
        diff[i] += diff[i - 1];
    sort(diff.rbegin(), diff.rend());
    sort(v.rbegin(), v.rend());
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += diff[i] * v[i];
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