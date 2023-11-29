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
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;
    sort(v.begin(), v.end());
    if (v.front() == v.back())
    {
        cout << 0 << '\n';
        return;
    }
    vector<int> ans;
    while (1)
    {
        set<int> st;
        int mi = *min_element(v.begin(), v.end());
        int l;
        if (mi & 1)
            l = 1;
        else
            l = 2;
        for (int i = 0; i < n; i++)
        {
            int k = (v[i] + l) / 2;
            st.insert(k);
            v[i] = k;
        }
        ans.push_back(l);
        if (st.size() == 1)
            break;
    }
    cout << ans.size() << '\n';
    if (ans.size() <= n)
    {
        for (auto x : ans)
            cout << x << ' ';
        cout << '\n';
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case " << cs << ": ";
        solve();
    }
    return 0;
}