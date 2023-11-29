#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    bool ok = true;
    for (int i = 1; i < n; i++)
    {
        if (s[i - 1] == s[i])
            ok = false;
    }
    if (ok)
    {
        cout << "Yes" << '\n';
        return;
    }
    bool okk = false;
    for (int i = 1; i < m; i++)
    {
        if (t[i - 1] == t[i])
            okk = true;
    }
    if (okk)
    {
        cout << "No" << '\n';
        return;
    }
    string ss;
    ss.push_back(s[0]);
    for (int i = 1; i < n; i++)
    {
        if (s[i - 1] == s[i])
        {
            ss += t;
            ss.push_back(s[i]);
        }
        else
        {
            ss.push_back(s[i]);
        }
    }
    // cout << ss << '\n';
    ok = true;
    for (int i = 1; i < ss.size(); i++)
    {
        if (ss[i - 1] == ss[i])
            ok = false;
    }
    if (ok)
    {
        cout << "Yes" << '\n';
    }
    else
    {
        cout << "No" << '\n';
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
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}