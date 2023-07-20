#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
const ll M = 998244353;
vector<ll> a(61), b(61);
ll nCr(ll n, ll r)
{
    ll ans = 1;
    for (ll i = 1; i <= r; i++)
    {
        ans *= (n - i + 1);
        ans /= i;
    }
    return ans % M;
}
void solve()
{
    int n;
    cin >> n;
    cout << a[n] << ' ' << b[n] << ' ' << 1 << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    a[2] = 1, b[2] = 0;
    for (int i = 4; i <= 60; i += 2)
    {
        a[i] = (nCr(i - 1, i / 2 - 1) + b[i - 2]) % M;
        b[i] = (nCr(i - 2, i / 2 - 2) + a[i - 2]) % M;
    }
    int t;
    t = 1;
    cin >> t;
    while (t--)
    {

        solve();
    }

    return 0;
}
