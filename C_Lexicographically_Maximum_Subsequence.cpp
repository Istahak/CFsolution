#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<pair<char, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        auto &[c, x] = v[i];
        c = s[i], x = -i;
    }
    sort(v.rbegin(), v.rend());
    string ans;
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        auto &[c, x] = v[i];
        if ((-x) >= k)
        {
            k = -x;
            ans.push_back(c);
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