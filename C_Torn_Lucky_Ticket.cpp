#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll ff(ll n)
{
    n = n * (n - 1);
    n /= 2;
    return n;
}
void solve()
{
    int n;
    cin >> n;
    map<pair<int, int>, ll> mp;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        v[i] = s;
        int sz = s.size();
        int sum = 0;
        for (auto &x : s)
        {
            sum += (x - '0');
        }
        mp[{sz, sum}]++;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        string cur = v[i];
        int len = cur.size();
        int sum = 0;
        for (auto x : cur)
        {
            sum += (x - '0');
        }
        for (int j = 1; j <= len; j++)
        {
            if ((j + len) & 1)
                continue;
            if (len == j)
            {
                ans += mp[{len, sum}];
            }
            else
            {
                int cc = (len + j) / 2;
                int one = 0, two = 0;
                for (int k = 0; k < cc; k++)
                {
                    one += (cur[k] - '0');
                }
                for (int k = len - 1; k >= len - cc; k--)
                {
                    two += (cur[k] - '0');
                }
                ans += mp[{j, 2*1ll * one - sum}];
                ans += mp[{j, 2 *1ll* two - sum}];
            }
        }

        // cout << ans << '\n';
    }
    cout << ans << '\n';
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