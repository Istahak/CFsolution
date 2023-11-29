#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, x;
    cin >> n >> x;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        if (p <= x)
            ans += p;
    }
    cout << ans << '\n';
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