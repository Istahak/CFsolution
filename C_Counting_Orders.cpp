#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int mod = 1e9 + 7;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    ll ans = 1;

    for (int i = 0; i < n; i++)
    {
        auto ff = upper_bound(a.begin(), a.end(), b[i]) - a.begin();
        ll gg = n - ff;
        ans = ((ans % mod) * ((gg - i + mod) % mod)) % mod;
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