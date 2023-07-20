#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;
    if (n == 2)
    {
        cout << max(abs(v[0] - v[1]) * 2ll, v[0] + v[1]) << endl;
    }
    else if (n == 3)
    {
        vector<ll> ans;
        ans.push_back(v[0] + v[1] + v[2]);
        ans.push_back(v[0] * 3ll);
        ans.push_back(v[2] * 3ll);
        ans.push_back(abs(v[2] - v[0]) * 3ll);
        ans.push_back(abs(v[1] - v[0]) * 3ll);
        ans.push_back(abs(v[2] - v[1]) * 3ll);

        ll mx = *max_element(ans.begin(), ans.end());
        cout << mx << endl;
    }
    else
    {
        ll mx = *max_element(v.begin(), v.end());

        cout << mx * n * 1ll << endl;
    }
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