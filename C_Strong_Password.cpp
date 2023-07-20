#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 3e5 + 10;
vector<int> cnt[10];

int n;
string l, r;
int dp[12][N];
int ff(int prepos, int x)
{
    auto it = upper_bound(cnt[x].begin(), cnt[x].end(), prepos);
    if (it == cnt[x].end())
        return -2;
    else
        return (*it);
}
int f(int pos, int prepos)
{

    if (pos == n)
    {
        return false;
    }
    int &ret = dp[pos][prepos];
    if (ret != -1)
        return ret;
    int st = l[pos] - '0';
    int h = r[pos] - '0';
    ret = 0;
    for (int i = st; i <= h; i++)
    {
        int newpos = ff(prepos, i);

        if (newpos == -2)
        {
            ret |= true;
        }
        else
        {
            ret |= f(pos + 1, newpos);
        }
    }
    return ret;
}
void solve()
{
    string s;
    cin >> s;
    for (int i = 0; i < 10; i++)
    {
        cnt[i].clear();
    }
    for (int i = 0; i < s.size(); i++)
    {
        cnt[s[i] - '0'].push_back(i + 1);
    }
    cin >> n >> l >> r;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s.size(); j++)
        {
            dp[i][j] = -1;
        }
    }
    cout << (f(0, 0) ? "YES" : "NO") << endl;
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