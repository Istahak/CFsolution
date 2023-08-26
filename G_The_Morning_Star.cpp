#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll f(ll x)
{
    ll cur = x * (x - 1);
    return cur;
}
void solve()
{
    ll n;
    cin >> n;
    map<int, ll> mp1, mp2, mpx, mpy;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        mpx[x]++, mpy[y]++;
        mp1[x + y]++, mp2[x - y]++;
    }
    ll ans = 0;
    for (auto [x, y] : mp1)
        ans += f(y);
    for (auto [x, y] : mp2)
        ans += f(y);
    for (auto [x, y] : mpx)
        ans += f(y);
    for (auto [x, y] : mpy)
        ans += f(y);
    cout << ans << endl;
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