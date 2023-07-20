#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll dp[50];
ll f(ll n)
{
    if (n == 0 || n == 1)
        return 1ll;
    else if (dp[n] != -1)
        return dp[n];
    return dp[n] = f(n - 1) + f(n - 2);
}

bool ans(ll n, ll x, ll y)
{
    while (n != 1)
    {
        y = min(y, dp[n + 1] - y + 1);
        ll nxt = dp[n + 1] - dp[n];
        if (y > nxt)
        {
            return false;
        }
        n--;
        ll temp = x;
        x = y;
        y = temp;
    }
    return true;
}

void solve()
{
    ll n, x, y;
    cin >> n >> x >> y;
    cout << (ans(n, x, y) ? "YES" : "NO") << endl;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    f(49);
    dp[0] = 1;
    dp[1] = 1;
    // for (int i = 0; i < 10; i++)
    //     cout << dp[i] << endl;
    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }

    return 0;
}