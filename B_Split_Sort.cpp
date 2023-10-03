#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;
    vector<int> dp(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        dp[v[i]] = 1;
        dp[v[i]] += dp[v[i] - 1];
    }
    int ans = 0;
    for (int i = 1; i <= n;)
    {
        int cur = 1;
        while (i <= n and dp[i] == cur)
        {
            cur++, i++;
        }
        ans++;
    }
    cout << ans - 1 << endl;
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