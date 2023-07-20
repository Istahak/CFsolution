#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a, b, c;
    for (int i = 0; i < n; i++)
    {
        int x;
        string s;
        cin >> x >> s;
        if (s[0] == '1' && s[1] != '1')
            a.push_back(x);
        if (s[1] == '1' && s[0] != '1')
            b.push_back(x);
        if (s[1] == '1' && s[0] == '1')
            c.push_back(x);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    int ans = INT_MAX;
    if (a.size() >= 1 && b.size() >= 1)
    {
        ans = a[0] + b[0];
    }
    if (c.size() >= 1)
        ans = min(ans, c[0]);
    if (ans == INT_MAX)
    {
        cout << -1 << endl;
        return;
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}