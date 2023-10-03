#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    bool prefix = true, suffix = true;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != t[i])
            prefix = false;
    }
    int j = m - 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] != t[j])
            suffix = false;
        j--;
    }
    int ans = 0;
    if (prefix and suffix)
        ans = 0;
    else if (prefix)
        ans = 1;
    else if (suffix)
    {
        ans = 2; /* code */
    }
    else
        ans = 3;
    cout << ans << '\n';
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