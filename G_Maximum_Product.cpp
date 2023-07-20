#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll dp[20][2][2][2];
ll f(string l, string r, int pos, int taken_l, int taken_r, int leadingzero)
{

    if (r[pos] == '\0')
        return 1;
    ll &ret = dp[pos][taken_l][taken_r][leadingzero];

    if (ret != -1)
        return ret;
    int h = 9, st = 0;
    if (!taken_r)
        h = r[pos] - '0';
    if (!taken_l)
        st = l[pos] - '0';
    ret = 0;
    for (int i = st; i <= h; i++)
    {
        if (i == 0)
        {
            if (!leadingzero)
            {
                ret = max(ret, f(l, r, pos + 1, (i > st or taken_l), (i < h or taken_r), 0) * 1);
            }
            if (leadingzero)
            {
                ret = max(ret, f(l, r, pos + 1, (i > st or taken_l), (i < h or taken_r), 1) * 0);
            }
        }
        else
        {
            ret = max(ret, f(l, r, pos + 1, (i > st or taken_l), (i < h or taken_r), 1) * i);
        }
    }
    return ret;
}

void print(string l, string r, int pos, int taken_l, int taken_r, int leadingzero)
{

    if (r[pos] == '\0')
        return;
    ll tem = dp[pos][taken_l][taken_r][leadingzero];

    int h = 9, st = 0;
    if (!taken_r)
        h = r[pos] - '0';
    if (!taken_l)
        st = l[pos] - '0';
    ll ret = 0;
    for (int i = st; i <= h; i++)
    {
        if (i == 0)
        {
            if (!leadingzero)
            {
                ret = f(l, r, pos + 1, (i > st or taken_l), (i < h or taken_r), 0) * 1;
                if (ret == tem)
                {
                    print(l, r, pos + 1, (i > st or taken_l), (i < h or taken_r), 0);
                    return;
                }
            }
            if (leadingzero)
            {
                ret = f(l, r, pos + 1, (i > st or taken_l), (i < h or taken_r), 0) * 0;
                if (ret == tem)
                {
                    cout << 0;
                    print(l, r, pos + 1, (i > st or taken_l), (i < h or taken_r), 1);
                    return;
                }
            }
        }
        else
        {
            ret = f(l, r, pos + 1, (i > st or taken_l), (i < h or taken_r), 1) * i;
            if (ret == tem)
            {
                cout << i;
                print(l, r, pos + 1, (i > st or taken_l), (i < h or taken_r), 1);
                return;
            }
        }
    }
}

void solve()
{
    string l, r;
    cin >> l >> r;
    if (l == r)
    {
        cout << l << endl;
        return;
    }
    int sz = r.size() - l.size();
    string s(sz, '0');
    l = s + l;
    memset(dp, -1, sizeof(dp));
    f(l, r, 0, 0, 0, 0);
    print(l, r, 0, 0, 0, 0);
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