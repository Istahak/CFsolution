#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b > d)
    {
        cout << -1 << endl;
        return;
    }
    int f = c - a + b;
    if (f > d)
    {
        cout << -1 << endl;
        return;
    }
    int ans = c - a + 2 * abs(d - f);
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