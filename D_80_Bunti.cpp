#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    map<string, set<pair<int, int>>> mp;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        string xx;
        for (int i = 1; i < s.size() - 1; i++)
            xx.push_back(s[i]);
        mp[xx].insert({s[0], s.back()});
    }
    int ans = 0;
    for (auto [st, v] : mp)
    {
        if (v.size() == 1)
            continue;
        vector<pair<int, int>> nv;
        for (auto [x, y] : v)
            nv.push_back({x, y});
        for (int i = 0; i < nv.size(); i++)
        {
            for (int j = 0; j < nv.size(); j++)
            {
                auto [fx, fy] = nv[i];
                auto [sx, sy] = nv[j];
                ans = max(ans, abs(fx - sx) + abs(fy - sy));
            }
        }
    }
    cout << ans << endl;
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