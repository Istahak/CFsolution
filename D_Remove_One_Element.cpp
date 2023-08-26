#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n + 2), dp(n + 1, 0), dpp(n + 1, 0);
    v[0] = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        if (v[i] > v[i - 1])
            dp[i] = dp[i - 1] + 1;
        else
            dp[i] = 1;
        ans = max(ans, dp[i]);
    }
    v[n + 1] = 0;
    for (int i = n; i >= 1; i--)
    {
        dpp[i] = 1;
        if (v[i + 1] > v[i])
            dpp[i] += dpp[i + 1];
    }

    for (int i = 1; i < n; i++)
    {
        if (v[i - 1] < v[i + 1])
            ans = max(ans, dp[i - 1] + dpp[i + 1]);
    }
    cout << ans << endl;
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