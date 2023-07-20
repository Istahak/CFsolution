#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    ll n;
    cin >> n;

    ll x = (ll)sqrtl(n);
    if (x * x == n)
    {
        cout << x - 1 << endl;
    }
    else
        cout << x << endl;
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
