#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve()
{
    int m, n;
    cin >> m >> n;
    map<string, ll> mp;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int mask = 0; mask < (1 << 8); mask++)
        {
            int bitcount = __builtin_popcount(mask);
            if (bitcount >= 6)
            {
                string ss;
                for (int k = 0; k < 8; k++)
                {
                    if ((1 << k) & mask)
                    {
                        ss.push_back(s[k]);
                    }
                }
                mp[ss]++;
                // cout << ss << endl;
            }
        }
    }
    while (m--)
    {
        string s;
        int d;
        cin >> s >> d;
        ll ans = 0;
        for (int mask = 0; mask < (1 << 8); mask++)
        {
            int bitcount = __builtin_popcount(mask);
            int unset = 8 - bitcount;
            if (unset <= d)
            {
                string ss;
                for (int k = 0; k < 8; k++)
                {
                    if ((1 << k) & mask)
                    {
                        ss.push_back(s[k]);
                    }
                }
                ans += mp[ss];
                // cout << ss << endl;
            }
        }
        cout << ans << endl;
    }
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