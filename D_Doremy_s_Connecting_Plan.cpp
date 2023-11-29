#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    ll n, c;
    cin >> n >> c;
    vector<pair<ll, ll>> v;
    ll total = 0;
    for (ll i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        if (i == 1)
        {
            total += x;
        }
        else if (i * c <= (x + total))
        {
            total += x;
        }
        else
        {
            v.push_back({i * c - x, x});
        }
    }
    sort(v.begin(), v.end());
    for (auto [p, val] : v)
    {
        if (p <= (total))
        {
            total += val;
        }
        else
        {
            cout << "No" << '\n';
            return;
        }
    }
    cout << "Yes" << '\n';
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