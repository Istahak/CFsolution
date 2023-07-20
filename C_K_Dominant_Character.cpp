#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<int> v[26];
    for (int i = 0; i < 26; i++)
        v[i].push_back(-1);
    for (int i = 0; i < n; i++)
    {
        v[s[i] - 'a'].push_back(i);
    }
    for (int i = 0; i < 26; i++)
        v[i].push_back(n);
    int ans = n;
    for (auto vv : v)
    {
        int cur = 0;
        for (int i = 1; i < (int)vv.size(); i++)
        {
            cur = max(cur, vv[i] - vv[i - 1]);
        }
        ans = min(ans, cur);
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