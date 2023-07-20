#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int M = 1e9 + 7;
void solve()
{
    ll n;
    cin >> n;
    // ll ans = 1;
    ll x = (n % M);
    x = ((x % M) * ((n + 1) % M)) % M;
    x = ((x % M) * (((2ll * n) % M + 1) % M)) % M;
    // x /= 6;
    x = (x * 674) % M;

    // x*=2;
    ll y = ((n % M) * ((n + 1) % M)) % M;
    y = (y * 1011) % M;

    ll ans = ((x % M) - (y % M) + M) % M;
    //  ans = ((ans % M) * 2022ll) % M;
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