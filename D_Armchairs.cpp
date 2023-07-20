#include <bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll> fiv, nfiv;
ll dp[5004][5004];
int n;
ll rec(int x, int y)
{
    if (x == (int)fiv.size())
        return 0LL;
    if (y == (int)nfiv.size())
        return 1e9 * 1LL;
    if (dp[x][y] != -1)
        return dp[x][y];
    ll ans = rec(x + 1, y + 1) + abs(fiv[x] - nfiv[y]);
    ans = min(ans, rec(x, y + 1));
    return dp[x][y] = ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x)
            fiv.push_back(i);
        else
            nfiv.push_back(i);
    }
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0) << endl;

    return 0;
}