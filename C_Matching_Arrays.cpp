#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> aa(n);
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        auto &[x, y] = a[i];
        cin >> aa[i];
        x = aa[i], y = i;
    }
    vector<int> b(n);
    for (auto &x : b)
        cin >> x;
    // auto aa = a;
    sort(a.begin(), a.end());

    sort(b.begin(), b.end());
    vector<int> ans(n);
    int id = 0;
    for (int i = n - x; i < n; i++)
    {
        auto [val, p] = a[i];
        ans[p] = b[id];
        id++;
    }
    for (int i = 0; i < n - x; i++)
    {
        auto [val, p] = a[i];
        ans[p] = b[id];
        id++;
    }
    // debug(), dbg(ans);
    int ok = 0;
    for (int i = 0; i < n; i++)
    {
        if (aa[i] > ans[i])
            ok++;
    }
    // cout << ok << ' ' << x << "\n";
    if (ok == x)
    {
        cout << "YES" << '\n';
        for (auto a : ans)
            cout << a << ' ';
        cout << '\n';
    }
    else
    {
        cout << "NO" << '\n';
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