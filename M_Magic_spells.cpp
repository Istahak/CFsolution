#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    string s;
    cin >> s;
    vector<int> pos[26];
    for (int i = 0; i < s.size(); i++)
    {
        pos[s[i] - 'a'].push_back(i + 1);
    }
    int q;
    cin >> q;
    while (q--)
    {
        string a;
        cin >> a;
        string ans;
        int cur = 0;
        for (auto c : a)
        {
            auto up = upper_bound(pos[c - 'a'].begin(), pos[c - 'a'].end(), cur);
            if (up == pos[c - 'a'].end())
                break;

            int ccur = up - pos[c - 'a'].begin();
            ccur = pos[c - 'a'][ccur];
            if (ccur < cur)
                break;
            cur = ccur;

            ans.push_back(c);
        }
        if (ans.size() == 0)
        {
            ans = "IMPOSSIBLE";
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