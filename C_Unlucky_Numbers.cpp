#include <bits/stdc++.h>
#define ll long long int
using namespace std;
string l, r;
ll dp[20][2][2][2][10][10];
ll f(int pos, int taken_l, int taken_r, int leadingzero, int mx, int mn)
{

    if (r[pos] == '\0')
    {
        return mx - mn;
    }
    ll &ret = dp[pos][taken_l][taken_r][leadingzero][mx][mn];

    if (ret != -1)
        return ret;
    int h = 9, st = 0;
    if (!taken_r)
        h = r[pos] - '0';
    if (!taken_l)
        st = l[pos] - '0';
    ret = 20;
  
    for (int i = st; i <= h; i++)
    {
        if (i == 0)
        {
            if (!leadingzero)
            {
                ret = min(ret, f(pos + 1, (i > st or taken_l), (i < h or taken_r), 0, 0, 9));
            }
            if (leadingzero)
            {
                ret = min(ret, f(pos + 1, (i > st or taken_l), (i < h or taken_r), 1, max(mx, 0), min(mn, 0)));
            }
        }
        else
        {
            //   cout << st << ' ' << h <<" "<<taken_l<<' '<<taken_r<<" "<<i<< endl;
            ret = min(ret, f(pos + 1, (i > st or taken_l), (i < h or taken_r), 1, max(mx, i), min(mn, i)));
        }
    }
    return ret;
}
void print(int pos, int taken_l, int taken_r, int leadingzero, int mx, int mn)
{

    if (r[pos] == '\0')
    {
        return;
    }
    ll tem = dp[pos][taken_l][taken_r][leadingzero][mx][mn];

    int h = 9, st = 0;
    if (!taken_r)
        h = r[pos] - '0';
    if (!taken_l)
        st = l[pos] - '0';
    ll ret = 20;
    for (int i = st; i <= h; i++)
    {
        if (i == 0)
        {
            if (!leadingzero)
            {
                ret = f(pos + 1, (i > st or taken_l), (i < h or taken_r), 0, 0, 9);
                if (tem == ret)
                {
                    print(pos + 1, (i > st or taken_l), (i < h or taken_r), 0, 0, 9);
                    return;
                }
            }
            if (leadingzero)
            {
                ret = f(pos + 1, (i > st or taken_l), (i < h or taken_r), 1, max(mx, 0), min(mn, 0));
                if (tem == ret)
                {
                    cout << 0;
                    print(pos + 1, (i > st or taken_l), (i < h or taken_r), 1, max(mx, 0), min(mn, 0));
                    return;
                }
            }
        }
        else
        {
            ret = f(pos + 1, (i > st or taken_l), (i < h or taken_r), 1, max(mx, i), min(mn, i));
            if (tem == ret)
            {
                cout << i;
                print(pos + 1, (i > st or taken_l), (i < h or taken_r), 1, max(mx, i), min(mn, i));
                return;
            }
        }
    }
}
void solve()
{
    cin >> l >> r;
    int sz = r.size() - l.size();
    string s(sz, '0');
    l = s + l;
    memset(dp, -1, sizeof(dp));
    f(0, 0, 0, 0, 0, 9);
    print(0, 0, 0, 0, 0, 9);
    cout << endl;
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