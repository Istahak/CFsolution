#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n + 1), dp(n + 1), best(n + 1, -1e9);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = max(dp[i - 1], best[v[i]] + i);
        best[v[i]] = max(best[v[i]], dp[i - 1] - (i - 1));
    }
    cout << dp[n] << endl;
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