#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    if (n == 1)
    {
        cout << "NO\n";
        return;
    }
    if (n == 2 and s[0] == s[1])
    {
        cout << "YES\n";
    }
    else if (n == 2 and s[0] != s[1])
    {
        cout << "NO\n";
    }
    else
    {
        bool ok = true;
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] > s[i + 1])
                ok = false;
        }
        cout << (ok ? "YES\n" : "NO\n");
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