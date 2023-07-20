#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    int ans = 0;
    auto ce = [&](int vv)
    {
        int dd = (vv + k - 1) / k;
        return dd;
    };
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, ce(i) + ce(n - i));
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