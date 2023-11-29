#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<ll> v(2 * n);
    for (auto &x : v)
        cin >> x;
    sort(v.begin(), v.end());
    ll ans = 0;
    vector<int> xx, yy;
    xx.push_back(v[0]);
    for (int i = 1; i < n; i++)
    {
        ans += abs(v[i] - v[i - 1]);
        xx.push_back(v[i]);
    }
    yy.push_back(v[n]);
    for (int i = n + 1; i < 2 * n; i++)
    {
        ans += abs(v[i] - v[i - 1]);
        yy.push_back(v[i]);
    }

    cout << ans << '\n';
    for (int i = 0; i < n; i++)
        cout << xx[i] << ' ' << yy[i] << '\n';
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