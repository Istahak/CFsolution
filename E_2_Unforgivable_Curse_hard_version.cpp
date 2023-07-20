#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int n, k;
string s, t;
void solve()
{
    cin >> n >> k;
    cin >> s >> t;
    string f = s, ff = t;
    sort(f.begin(), f.end());
    sort(ff.begin(), ff.end());
    if (f != ff)
    {
        cout << "NO" << endl;
        return;
    }
    bool ok = true;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != t[i])
        {
            if (i - k < 0 && i + k >= n)
                ok = false;
        }
    }
    cout << (ok ? "YES" : "NO") << endl;
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