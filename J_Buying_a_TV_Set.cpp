#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    ll a, b, x, y;
    cin >> a >> b >> x >> y;
    ll g = __gcd(x, y);
    x /= g, y /= g;
    cout << min(a / x, b / y) << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}