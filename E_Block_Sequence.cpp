#include <bits/stdc++.h>
#define ll long long int
using namespace std;
vector<int> v;
vector<int> dp;
int n;
int f(int pos)
{
    if (pos >= n)
        return 0;
    int &ret = dp[pos];
    if (~ret)
        return ret;
    if (v[pos] > (n - pos - 1))
    {
        ret = 1 + f(pos + 1);
    }
    else
    {
        ret = 1 + f(pos + 1);
        ret = min(ret, f(pos + v[pos] + 1));
    }
    return ret;
}
void solve()
{

    cin >> n;
    v.resize(n);
    for (auto &x : v)
        cin >> x;
    dp.assign(n, -1);
    cout << f(0) << '\n';
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