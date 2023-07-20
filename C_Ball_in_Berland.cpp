#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
ll func(ll n)
{
    map<ll, ll> mp;
    ll ans = 0;
    while (n--)
    {
        ll x;
        cin >> x;
        ans += mp[x]++;
    }
    return ans;
}
void solve()
{
    ll a, b, k;
    cin >> a >> b >> k;
    ll ans = (k * (k - 1)) / 2;
    ans -= func(k);
    ans -= func(k);
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
