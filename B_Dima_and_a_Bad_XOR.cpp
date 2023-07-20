#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 505;
int dp[N][1030];
int grid[N][N];
int n, m;
vector<int> ans;
bool f(int pos, int Xor)
{
    if (pos == n + 1)
    {
        return Xor > 0;
    }
    int &ret = dp[pos][Xor];
    if (~ret)
        return ret;
    ret = 0;
    for (int i = 1; i <= m; i++)
    {

        int cur = f(pos + 1, Xor ^ grid[pos][i]);
        if (cur)
            return ret = cur;
    }

    return ret;
}
void print(int pos, int Xor)
{
    if (pos == n + 1)
    {
        return;
    }
    int tem = dp[pos][Xor];

    int ret = 0;
    for (int i = 1; i <= m; i++)
    {
        int cur = f(pos + 1, Xor ^ grid[pos][i]);
        if (tem == cur)
        {
            ans.push_back(i);
            print(pos + 1, Xor ^ grid[pos][i]);
            return;
        }
    }

    return;
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> grid[i][j];
    }
    memset(dp, -1, sizeof(dp));
    bool ok = f(1, 0);
    if (!ok)
    {
        cout << "NIE" << endl;
        return;
    }
    print(1, 0);
    ok &= (ans.size() == n);
    if (!ok)
    {
        cout << "NIE" << endl;
        return;
    }
    cout << "TAK" << endl;
    for (auto x : ans)
        cout << x << ' ';
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