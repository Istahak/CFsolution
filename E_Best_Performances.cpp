#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif

void solve()
{
    int n, q, k;
    cin >> n >> k >> q;
    vector<int> v(n + 1);
    multiset<pair<ll, int>> take, other;
    ll ans = 0;
    while (q--)
    {
        ll pos, val;
        cin >> pos >> val;
        if (take.size() < k)
        {
            if (take.count({v[pos], pos}))
            {
                take.erase({v[pos], pos});
                ans -= v[pos];
                take.insert({val, pos});
                ans += val;
            }
            else
            {

                take.insert({val, pos});
                ans += val;
            }
        }
        else
        {
            if (take.count({v[pos], pos}))
            {
                take.erase({v[pos], pos});
                ans -= v[pos];
                take.insert({val, pos});
                ans += val;
            }
            else if (other.count({v[pos], pos}))
            {
                other.erase({v[pos], pos});
                other.insert({val, pos});
            }
            else
            {
                other.insert({val, pos});
            }
            if (!other.empty())
            {
                auto l = *take.begin();
                auto r = *other.rbegin();
                if (l.first <= r.first)
                {
                    ans -= l.first;
                    ans += r.first;
                    take.erase(l);
                    take.insert(r);
                    other.erase(r);
                    other.insert(l);
                }
            }
        }
        cout << ans << '\n';

        v[pos] = val;
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
        // cout << "Case " << cs << ": ";
        solve();
    }
    return 0;
}