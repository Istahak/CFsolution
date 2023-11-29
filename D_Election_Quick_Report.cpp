#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n + 1, 0);
    multiset<pair<int, int>> st;
    while (q--)
    {
        int x;
        cin >> x;
        if (v[x] == 0)
        {
            v[x]++;
            st.insert({v[x], -x});
        }
        else
        {
            st.erase({v[x], -x});
            v[x]++;
            st.insert({v[x], -x});
        }
        auto [_, ans] = *st.rbegin();
        cout << ans * (-1) << '\n';
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