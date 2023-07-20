#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n;
    cin >> n;
    vector<string> v(2);
    for (auto &s : v)
        cin >> s;
    bool dp[n + 1][2];
    memset(dp, 0, sizeof(dp));
    if (v[0][0] == 'B')
        dp[0][0] = true;
    if (v[1][0] == 'B')
        dp[0][1] = true;

    for (int i = 1; i < n; i++)
    {
        if (v[0][i] == 'B' && v[1][i] == 'B')
        {
            dp[i][0] |= dp[i - 1][1];
            dp[i][1] |= dp[i - 1][0];
        }
        else if (v[0][i] == 'B')
        {
            dp[i][0] |= dp[i - 1][0];
        }
        else
        {
            dp[i][1] |= dp[i - 1][1];
        }
    }
    bool ok = dp[n-1][1] | dp[n-1][0];
    cout << (ok ? "YES" : "NO") << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    cin >> t;
    while (t--)
    {

        solve();
    }

    return 0;
}