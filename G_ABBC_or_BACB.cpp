#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 5110;
const int INF = 1e8;
const int M = 998244353;
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<int> pos;
    for (int i = 0; i < n; ++i)
        if (s[i] == 'B')
            pos.push_back(i);
    vector<int> v(n, 0);
    for (int i = 0; i < n; ++i)
        if (s[i] == 'A')
            v[i] = 1;
    for (int i = 1; i < n; ++i)
        v[i] += v[i - 1];
    if (pos.size() == 1)
    {
        cout << max(v[n - 1] - v[pos[0]], v[pos[0]]) << endl;
        return;
    }
    int ans = 0;
    for (int i = 1; i < pos.size(); ++i)
    {
        int l = pos[i - 1];
        int r = pos[i];
        ans = max(ans, v[n - 1] - v[r] + v[l]);
        ans = max(ans, v[r] - v[l] + max(v[n - 1] - v[r], v[l]));
    }
    cout << ans << endl;
}
int main()
{
    int t = 1;
    cin >> t;
    // prec();
    for (int tt = 1; tt <= t; ++tt)
    {
        // cout << "Case " << tt << ": ";
        solve();
    }
    return 0;
}