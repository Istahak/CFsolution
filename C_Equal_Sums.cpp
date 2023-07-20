#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int k;
    cin >> k;
    map<ll, vector<pair<int, int>>> mp;
    for (int i = 1; i <= k; i++)
    {
        ll sum = 0;
        int n;
        cin >> n;
        vector<int> v(n + 1);
        for (int j = 1; j <= n; j++)
        {
            cin >> v[j];
            sum += v[j];
        }
        map<ll, bool> f;
        for (int j = 1; j <= n; j++)
        {
            if (f.find(v[j]) == f.end())
            {
                mp[sum - v[j]].push_back({i, j});
                f[v[j]] = true;
            }
        }
    }

    for (auto [s, v] : mp)
    {
        int sz = v.size();
        if (sz >= 2)
        {
            cout << "YES" << endl;
            auto [s1, e1] = v[0];
            cout << s1 << ' ' << e1 << endl;
            auto [s2, e2] = v[1];
            cout << s2 << ' ' << e2 << endl;
            return;
        }
    }
    cout << "NO" << endl;
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