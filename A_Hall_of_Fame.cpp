#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = -1;
    bool ok = false;
    for (int i = 1; i < n; i++)
    {
        if (s[i - 1] == 'L' && s[i] == 'R')
            ans = i;
        if (s[i - 1] == 'R' && s[i] == 'L')
            ok = true;
    }
    if (ok)
        cout << 0 << endl;
    else
        cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}