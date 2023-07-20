#include <bits/stdc++.h>
using ll = long long;
using bl = __int128;
using namespace std;
ll colcost(vector<ll> v, ll sum)
{
    sort(v.begin(), v.end());
    ll cursum = 0;
    ll sz = v.size();
    for (int i = 0; i < sz; i++)
    {
        sum -= v[i];
        cursum += (sum - v[i] * (sz - i - 1));
    }
    return cursum;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> v(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ll x;
            cin >> x;
            v[i].push_back(x);
        }
    }
    ll ans = 0;
    for (int i = 0; i < m; i++)
    {
        ll sum = 0;
        vector<ll> a;
        for (int j = 0; j < n; j++)
        {
            a.push_back(v[j][i]);
            sum += v[j][i];
        }
        ans += colcost(a, sum);
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
