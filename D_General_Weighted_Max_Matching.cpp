#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int INF = 1e8;
const int N = 1e5 + 10;
ll ans[20][20];
ll dp[20][N];
int n;
ll ber_kor(int id, int s)
{
    if (id > n)
        return 0;
    if (dp[id][s] != -1)
        return dp[id][s];
    if ((s & (1 << id)))
        return dp[id][s] = ber_kor(id + 1, s);
    ll res = 0;
    for (int i = id + 1; i <= n; ++i)
    {
        if ((s & (1 << i)))
            continue;
        int k = s;
        k = k | (1 << i);
        k = k | (1 << id);
        ll temp = ans[id][i] + ber_kor(id + 1, k);
        res = max(res, temp);
    }
    if (n & 1)
        return dp[id][s] = max(res, ber_kor(id + 1, s));
    else
        return dp[id][s] = res;
}
void solve()
{
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i < n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            cin >> ans[i][j];
        }
    }
    cout << ber_kor(1, 0) << endl;
}
int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}