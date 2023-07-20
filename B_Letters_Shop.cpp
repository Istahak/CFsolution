#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    vector<int> vs[26];
    for (int i = 0; i < n; i++)
    {
        vs[s[i] - 'a'].push_back(i + 1);
    }
    int q;
    cin >> q;
    while (q--)
    {
        string ss;
        cin >> ss;
        int ans = -1;
        vector<int> vss(26, 0);
        for (auto c : ss)
            vss[c - 'a']++;
        for (int i = 0; i < 26; i++)
        {
            if (vss[i] == 0)
                continue;
            ans = max(ans, vs[i][vss[i] - 1]);
        }
        cout << ans << endl;
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