#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    ll n, m;
    cin >> n >> m;
    if (n == 1 && m == 1)
    {
        cout << 0 << endl;
        return;
    }
    ll ans = n + m - 2 + min(n, m);
    cout << ans << endl;
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