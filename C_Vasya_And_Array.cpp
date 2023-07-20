#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> ans(n + 1, 0);
    vector<int> v(n + 1, -1);
    vector<pair<int, int>> tt2;
    while (q--)
    {
        int ty;
        cin >> ty;
        if (ty)
        {
            int l, r;
            cin >> l >> r;
            for (int i = l; i <= r - 1; i++)
                v[i] = 0;
        }
        else
        {
            int l, r;
            cin >> l >> r;
            tt2.push_back({l, r});
        }
    }
    ans[1] = 1e9;
    for (int i = 2; i <= n; i++)
    {
        ans[i] = ans[i - 1] + v[i - 1];
    }
    for (auto [l, r] : tt2)
    {
        bool ok = true;
        for (int i = l; i <= r - 1; i++)
        {
            if (ans[i] > ans[i + 1])
                ok = false;
        }
        if (ok)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    cout << endl;
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