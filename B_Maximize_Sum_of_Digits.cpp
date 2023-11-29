#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif
string s;
int n;
int dp[20][2];
int f(int id, int istaken)
{
    if (id >= n)
        return 0;
    int &ret = dp[id][istaken];
    if (~ret)
        return ret;
    int r = s[id] - '0';
    if (istaken)
        r = 9;
    ret = f(id + 1, istaken);
    for (int d = 0; d <= r; d++)
    {
        ret = max(ret, f(id + 1, d < (s[id] - '0') or istaken) + d);
    }
    return ret;
}
string a;
void print(int id, int istaken)
{
    if (id >= n)
        return;
    int ret = dp[id][istaken];
    int r = s[id] - '0';
    if (istaken)
        r = 9;
    int tem = f(id + 1, istaken);
    if (tem == ret)
    {
        print(id + 1, istaken);
        // return;
    }
    int ans = 0;
    for (int d = 0; d <= r; d++)
    {
        tem = f(id + 1, d < (s[id] - '0') or istaken) + d;
        if (tem == ret)
        {
            ans = max(ans, d);
            print(id + 1, ans < (s[id] - '0') or istaken);
        }
    }

    a.push_back(ans + '0');
    return;
}
void solve()
{
    cin >> s;
    n = s.size();
    memset(dp, -1, sizeof(dp));
    f(0, 0);
    print(0, 0);
    reverse(a.begin(), a.end());
    while (a.size() > n)
        a.pop_back();
    while (a.front() == '0')
        a.erase(a.begin());
    cout << a << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case " << cs << ": ";
        solve();
    }
    return 0;
}