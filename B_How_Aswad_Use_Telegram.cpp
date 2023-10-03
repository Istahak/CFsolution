#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    const vector<string> s = {"blue", "green", "yellow", "red", "purple", "orange", "pink", "grey", "cyan", "brown", "ash", "silver", "gold", "white", "black"};
    string in;
    cin >> in;
    int n = s.size();
    vector<ll> c(26, 0);
    for (auto x : in)
    {
        c[x - 'a']++;
    }
    // cout << (1 << n) << '\n';
    int ans = 0;
    for (int mask = 0; mask < (1 << n); mask++)
    {
        // cout << mask << '\n';
        bool ok = true;
        vector<int> cc(26, 0);
        for (int k = 0; k < n; k++)
        {
            if ((mask & (1LL << k)))
            {
                auto cur = s[k];

                for (auto x : cur)
                {
                    cc[x - 'a']++;
                }
            }
        }
        for (int i = 0; i < 26; i++)
        {
            if (c[i] < cc[i])
                ok = false;
        }
        if (ok)
        {
            ans = max(ans, __builtin_popcount(mask));
        }
    }
    cout << ans << '\n';
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