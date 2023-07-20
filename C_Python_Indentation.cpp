#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 5005, mod = 1e9 + 7;
vector<char> v(N);
int dp[N][N], n;
int f(int index, int level)
{
    if (level < 0)
        return 0;
    if (index == n)
        return level == 0;
    int &ret = dp[index][level];
    if (ret != -1)
        return ret;

    if (v[index] == 'f')
    {
        return ret = f(index + 1, level + 1) % mod;
    }
    else
    {
        return ret = f(index + 1, level) % mod + f(index, level - 1) % mod;
    }
}
void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    memset(dp, -1, sizeof(dp));
    int ans = f(0, 0) % mod;
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