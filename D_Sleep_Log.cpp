#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif

void solve()
{
    int n;
    cin >> n;
    multiset<int> st, en;
    vector<ll> v(n);
    for (auto &X : v)
        cin >> X;
    vector<ll> prefix(n);
    for (int i = 2; i < n; i += 2)
    {
        prefix[i] = prefix[i - 2] + v[i] - v[i - 1];
        if (i + 1 < n)
            prefix[i + 1] = prefix[i];
    }
    auto pref = [&](int x)
    {
        int idx = upper_bound(v.begin(), v.end(), x) - v.begin();
        if (idx % 2 == 0)
        {
            return prefix[idx - 1] + x - v[idx - 1];
        }
        else
        {
            return prefix[idx - 1];
        }
    };
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << pref(r) - pref(l) << '\n';
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