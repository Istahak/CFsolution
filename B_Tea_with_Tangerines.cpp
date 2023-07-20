#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n;
    cin >> n;
    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;
    ll ans = 0, mi = v[0] + v[0] - 1;
    for (auto i : v)
        ans += (i - 1) / mi;

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