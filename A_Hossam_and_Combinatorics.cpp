#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    ll n;
    cin >> n;
    vector<int> v(n);
    map<int, ll> mp;
    for (auto &i : v)
    {
        cin >> i;
        mp[i]++;
    }

    int mx = *max_element(v.begin(), v.end());
    int mi = *min_element(v.begin(), v.end());
    if (mx == mi)
    {
        cout << n * (n - 1) * 1ll << endl;
        return;
    }

    cout << 2 * mp[mx] * mp[mi] * 1ll << endl;
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