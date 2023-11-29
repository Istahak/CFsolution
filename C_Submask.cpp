#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve()
{
    ll n;
    cin >> n;
    ll bit = __builtin_popcountll(n);
    for (ll mask = 0; mask < (1ll << bit); mask++)
    {
        ll cur = 0;
        ll bb = 0;
        for (ll i = 0; i < 61; i++)
        {
            if (n & (1ll << i))
            {
                if (mask & (1ll << bb))
                {
                    cur += (1ll << i);
                }
                bb++;
            }
        }
        cout << cur << '\n';
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