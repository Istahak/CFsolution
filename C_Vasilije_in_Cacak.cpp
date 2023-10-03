#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll f(ll n)
{
    ll tem = n * (n + 1);
    tem /= 2;
    return tem;
}
void solve()
{
    ll n, k, x;
    cin >> n >> k >> x;
    ll fi = f(k);
    ll sc = f(n) - f(n - k);
    if (fi <= x and x <= sc)
    {
        cout << "YES" << '\n';
    }
    else
        cout << "NO"
             << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}