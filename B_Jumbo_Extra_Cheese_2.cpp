#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n;
    cin >> n;
    vector<pair<ll, ll>> v(n);
    ll ans = 0;
    ll mx = INT_MIN;
    for (auto &i : v)
    {
        cin >> i.first >> i.second;
        ans += min(i.first, i.second);
        mx = max(mx, max(i.first, i.second));
    }
    ans *= 2;
    mx = mx + mx;
    ans += mx;
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    cin >> t;
    while (t--)
    {

        solve();
    }

    return 0;
}