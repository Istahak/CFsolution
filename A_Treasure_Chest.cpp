#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int x, y, k;
    cin >> x >> y >> k;
    if (x >= y)
    {
        cout << x << '\n';
        return;
    }
    if ((x + k) >= y)
    {
        cout << y << '\n';
        return;
    }
    int ans = x + k;
    ans += (y - ans) * 2;
    cout << ans << '\n';
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