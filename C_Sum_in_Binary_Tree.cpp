#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    ll n;
    cin >> n;
    ll ans = n;
    while (n)
    {
        ans += (n / 2);
        n /= 2;
    }
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