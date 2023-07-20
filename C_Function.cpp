#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll a, b, x;
ll rec(ll k)
{
    if (k > a)
        return k - b + 1;
    else
        return rec(rec(k + b));
}
void solve()
{
    cin >> a >> b >> x;
    ll ans = rec(x);
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
