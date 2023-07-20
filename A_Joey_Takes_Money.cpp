#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    ll n;
    cin >> n;
    ll ans = 1;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        ans *= x;
    }
    ans += (n - 1);
    ans *= 2022ll;
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