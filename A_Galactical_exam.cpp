#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    ll n, k;
    cin >> n >> k;
    int ans = 0;
    for (ll i = 1; i * i * 1LL <= k; i++)
    {
        if (k % i == 0)
        {
            ll x = i, y = k / i;
            if (x <= n && y <= n)
            {
                if (x == y)
                    ans++;
                else
                    ans += 2;
            }
        }
    }
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
