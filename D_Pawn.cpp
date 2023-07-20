#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 110;
char grid[N][N];
int dp[N][N][12];
int n, m, k;
string res;
int f(int x, int y, int d)
{
    if (x == 0)
    {
        return d == 0 ? d : INT_MIN;
    }
    int &ret = dp[x][y][d];
    if (~ret)
        return ret;
    int newd = (d + grid[x][y] - '0') % k;
    ret = INT_MIN;
    if (y - 1 >= 1)
        ret = max(ret, f(x - 1, y - 1, newd) + grid[x][y] - '0');
    if (y + 1 <= m)
        ret = max(ret, f(x - 1, y + 1, newd) + grid[x][y] - '0');
    return ret;
}
void print(int x, int y, int d)
{
    if (x == 0)
    {
        return;
    }
    int tem = dp[x][y][d];
    int newd = (d + grid[x][y] - '0') % k;
    int ret = INT_MIN;
    if (y - 1 >= 1)
    {
        ret = f(x - 1, y - 1, newd) + grid[x][y] - '0';
        if (ret == tem)
        {
            // cout << "L";
            res.push_back('L');
            print(x - 1, y - 1, newd);
            return;
        }
    }
    if (y + 1 <= m)
    {
        ret = f(x - 1, y + 1, newd) + grid[x][y] - '0';
        if (ret == tem)
        {
            // cout << "R";
            res.push_back('R');
            print(x - 1, y + 1, newd);
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    k++;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> grid[i][j];
    }
    memset(dp, -1, sizeof(dp));
    int ans = INT_MIN;
    int start = -1;
    for (int i = 1; i <= m; i++)
    {
        int cur = f(n, i, 0);
        if (cur > ans)
        {
            ans = cur;
            start = i;
        }
    }
    ans = max(ans, -1);
    cout << ans << endl;
    if (ans == -1)
        return 0;
    cout << start << endl;
    print(n, start, 0);
    res.pop_back();
    cout << res << endl;
    return 0;
}