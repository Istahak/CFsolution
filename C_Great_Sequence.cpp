#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    ll n, x, k;
    cin >> n >> k;
    map<ll, ll> mp;
    vector<ll> v(n);
    for (auto &i : v)
    {
        cin >> i;
        mp[i]++;
    }
    sort(v.begin(), v.end());
    ll ans = n;

    for (int i = 0; i < n; i++)
    {
        x = v[i] * k;
        if (mp[x] && mp[v[i]])
        {
            ans -= 2;
            mp[x]--;
            mp[v[i]]--;
        }
    }

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