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
    map<ll, ll> mp;
    for (auto &i : v)
    {
        cin >> i;
        mp[i]++;
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    for (int i = 1; i < n; i++)
    {
        ll sum = 2 * v[i] - v[i - 1] - mi;
        v1.push_back(sum);
        ans = max(ans, sum);
    }
    for (int i = 0; i < n - 1; i++)
    {
        ll sum = v[i + 1] - mx - 2 * v[i];
        v1.push_back(sum);

        ans = max(ans, sum);
    }
    ll mx1 = *max_element(v.begin(), v.end());
    ll mx2 = *max_element(v.begin(), v.end());

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