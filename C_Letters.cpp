#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m), prefix(n + 1, 0);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    int l = 0;
    ll sum = 0;
    ll pre = 0;
    bool ok = false;
    for (int i = 0; i < m; i++)
    {
        ll x = b[i];
        while (sum < x)
        {
            sum += a[l];
            l++;
            prefix[l] = sum;
            ok = true;
        }
        if (sum >= x)
        {
            // ll y = sum - a[l - 1];
            b[i] -= prefix[l - 1];
            // cout << sum << ' ' << a[l - 1] << ' ' << b[i] << endl;
            cout << l << ' ' << b[i] << endl;
        }
    }
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