#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    ll n;
    cin >> n;
    ll ans = 4 * n + n - 1;
    n -= 2;
    ll x = n * (n + 1);
    x++;
    ans += x;
    cout << ans << endl;
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