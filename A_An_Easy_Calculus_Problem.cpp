#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    if (n <= -3)
    {
        cout << -1 * (n + 4) * (n + 4) + 8 << endl;
    }
    else if (n > -3 && n <= 2)
    {
        cout << -2 * n + 1 << endl;
    }
    else if (n > 2)
    {
        int ans = (n * n * n) - (14 * n) + 17;
        cout << ans << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    // cin >> tt;
    while (tt--)
        solve();

    return 0;
}