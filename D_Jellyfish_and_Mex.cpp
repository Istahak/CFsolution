#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> freq(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x < n)
            freq[x]++;
    }
    int mex = 0;
    while (freq[mex] != 0)
        mex++;
    vector<int> dp(n + 1, 1e9);
    for (int i = mex; i <= n; i++)
        dp[i] = 0;

    for (int i = mex - 1; i >= 0; i--)
    {
        for (int j = i + 1; j <= n; j++)
        {
            dp[i] = min(dp[i],  (freq[i] - 1) * j + dp[j] + i);
        }
    }

    cout << dp[0] << '\n';
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