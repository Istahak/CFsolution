#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int m, d;
int dp[2002][2][3][2002];
const int mod = 1e9 + 7;
int f(int pos, int taken, int leading, int di, string &s)
{
    if (s[pos] == '\0')
        return di == 0;
    int &ret = dp[pos][taken][leading][di];
    if (~ret)
        return ret;
    ret = 0;
    int h = 9;
    if (!taken)
        h = s[pos] - '0';
    for (int i = 0; i <= h; i++)
    {
        if (i == d)
        {
            if (leading != 2 and leading != pos % 2)
            {
                ret += f(pos + 1, i < h or taken, leading, (di * 10 + i) % m, s);
                ret %= mod;
            }
        }
        else
        {
            int next_leading;

            if (leading == 2)
            {
                if (i == 0)
                    next_leading = 2;
                else
                    next_leading = pos % 2;
            }
            else
            {
                next_leading = leading;
            }
            if (leading == 2 or leading == pos % 2)
            {
                ret += f(pos + 1, i < h or taken, next_leading, (di * 10 + i) % m, s);
                ret %= mod;
            }
        }
    }
    return ret;
}
int fff(int pos, int taken, int leading, int di, string &s)
{
    if (s[pos] == '\0')
        return (di == 0 and taken);
    int &ret = dp[pos][taken][leading][di];
    if (~ret)
        return ret;
    ret = 0;
    int h = 9;
    if (!taken)
        h = s[pos] - '0';
    for (int i = 0; i <= h; i++)
    {
        if (i == d)
        {
            if (leading != 2 and leading != pos % 2)
            {
                ret += fff(pos + 1, i < h or taken, leading, (di * 10 + i) % m, s);
                ret %= mod;
            }
        }
        else
        {
            int next_leading;

            if (leading == 2)
            {
                if (i == 0)
                    next_leading = 2;
                else
                    next_leading = pos % 2;
            }
            else
            {
                next_leading = leading;
            }
            if (leading == 2 or leading == pos % 2)
            {
                ret += fff(pos + 1, i < h or taken, next_leading, (di * 10 + i) % m, s);
                ret %= mod;
            }
        }
    }
    return ret;
}
int ff(string &s)
{
    memset(dp, -1, sizeof(dp));
    return f(0, 0, 2, 0, s);
}

void solve()
{
    string l, r;
    cin >> m >> d;
    cin >> l >> r;
    int ans = ff(r);

    memset(dp, -1, sizeof(dp));
    ans -= fff(0, 0, 2, 0, l);
    ans += mod;

    cout << ans % mod << endl;
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