#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int M = 1e9 + 7;
void solve()
{
    ll n;
    cin >> n;
    ll ans = 1;
    for (ll i = 1; i <= n; i++)
    {
        ans = ((ans % M) * (i % M)) % M;
    }
    ans = ((ans % M) * (n % M)) % M;
    n--;
    ans = ((ans % M) * (n % M)) % M;
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