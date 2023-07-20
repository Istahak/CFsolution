#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    ll n;
    cin >> n;
    if (n & 1)
    {
        ll x = n / 2 + 1;
        n /= 2;
        ll ans = n * (n + 1);
        ans += x;
         ans=sqrtl(ans);

        cout << ans << endl;
    }
    else
    {
        n /= 2;
        ll ans = n * (n + 1);
         ans=sqrtl(ans);
        cout << ans << endl;
    }
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