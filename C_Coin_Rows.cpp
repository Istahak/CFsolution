#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    ll v[n + 1][2];
    for (int j = 0; j < 2; j++)
        for (int i = 1; i <= n; i++)
            cin >> v[i][j];
    ll suffixsum[n + 1];
    suffixsum[n] = v[n][0];
    for (int i = n - 1; i >= 1; i--)
    {
        suffixsum[i] = suffixsum[i + 1] + v[i][0];
    }
    ll prefixsum[n + 1];
    prefixsum[0] = 0;
    for (int i = 1; i <= n; i++)
        prefixsum[i] = prefixsum[i - 1] + v[i][1];

    ll ans = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        ll mn = max(prefixsum[i] - v[i][1], suffixsum[i] - v[i][0]);
        ans = min(mn, ans);
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