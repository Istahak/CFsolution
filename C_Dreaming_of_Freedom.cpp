#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    ll n, m;
    cin >> n >> m;
    if (n == 1 || m == 1)
    {
        cout << "YES" << endl;
        return;
    }
    vector<ll> di;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            di.push_back(n / i);
            di.push_back(i);
        }
    }
    di.push_back(n);
    bool ok = true;
    for (auto x : di)
    {
        if (m >= x)
            ok = false;
    }
    cout << (ok ? "YES" : "NO") << endl;
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