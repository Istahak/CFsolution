#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
ll u, v;
ll big(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll x = big(a, b / 2);
    if (b & 1)
        return x * x * a;
    else
        return x * x;
}
bool ispossible(ll mid)
{
    ll ans = 0;
    for (ll i = 1;; i++)
    {
        ans += (mid / big(v, i));
        if ((mid / big(v, i)) == 0)
            break;
    }
    return ans >= u;
}
ll Binaryserach(ll l, ll r)
{
    ll ans = -1;
    while (l <= r)
    {
        ll mid = l + ((r - l) / 2);

        if (ispossible(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return ans;
}
void solve()
{
    int M = 998244353;
    vector<ll> v(6);
    for (auto &i : v)
        cin >> i;

    ll x = ((((v[0] % M) * (v[1] % M)) % M) * (v[2] % M)) % M;
    ll y = ((((v[3] % M) * (v[4] % M)) % M) * (v[5] % M)) % M;
    cout << (x - y + M) % M << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    // cin >> t;
    while (t--)
    {

        solve();
    }

    return 0;
}