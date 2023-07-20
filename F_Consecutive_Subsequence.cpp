#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> dp;
    for (auto &x : v)
        cin >> x;
    int ans = 0, st = 0;
    for (int i = 0; i < n; i++)
    {
        int cur = v[i];
        dp[cur] = max(dp[cur], 1);
        dp[cur] = max(dp[cur], dp[cur - 1] + 1);
        if (dp[cur] > ans)
        {
            ans = dp[cur];
            st = cur - ans + 1;
        }
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == st)
        {
            cout << i + 1 << ' ';
            st++;
        }
    }
    cout << endl;
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