#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll n, x, p;
bool ok(ll f)
{
    ll kk = f * (f + 1);
    kk /= 2;
    kk += x;
    return kk % n == 0;
}
void solve()
{
    cin >> n >> x >> p;
    for (ll i = 1; i <= min(2 * n, p); i++)
    {

        if (ok(i))
        {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
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