#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int k, n, a, b;
string s;
vector<int> v, res;
int dp[202][202];
bool f(int pos, int sum)
{
    if (pos == k)
    {
        return sum == n;
    }
    int &ret = dp[pos][sum];
    if (~ret)
        return ret;
    ret = 0;
    for (auto x : v)
    {
        ret |= f(pos + 1, sum + x);
        ret |= f(pos + 1, sum);
    }
    return ret;
}
void print(int pos, int sum)
{
    if (pos == k)
    {
        return;
    }
    int tem = dp[pos][sum];

    int ret = 0;
    for (auto x : v)
    {
        ret |= f(pos + 1, sum + x);
        if (ret == tem)
        {
            res.push_back(x);
            print(pos + 1, sum + x);
            return;
        }
        ret |= f(pos + 1, sum);
        if (ret == tem)
        {

            print(pos + 1, sum);
            return;
        }
    }
    return;
}
void solve()
{

    cin >> k >> a >> b >> s;
    n = s.size();
    for (int i = a; i <= b; i++)
        v.push_back(i);
    memset(dp, -1, sizeof(dp));
    bool ok = f(0, 0);

    if (!ok)
    {
        cout << "No solution\n";
        return;
    }
    print(0, 0);
    ok &= (k == res.size());
    if (!ok)
    {
        cout << "No solution\n";
        return;
    }
    int i = 0;
    for (auto x : res)
    {
        for (int j = 0; j < x; j++)
        {
            cout << s[i++];
        }
        cout << endl;
    }

    //kkkkkkkkkkkkkk----------.............
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