#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, ll> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        mp[v[i]]++;
    }
    ll ans = 0;
    sort(v.begin(), v.end());
    ll f = 1;
    for (auto x : v)
    {
        while (mp[f])
        {
            f++;
        }
        if (f < x)
        {
            ans += (x - f);
            mp[f]++;
            mp[x]--;
        }
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}