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
    if (n >= 6)
    {
        cout << "YES" << endl;
        return;
    }
    if (n == 5)
    {
        if (s[2] == t[2])
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;

        return;
    }
    if (n == 4)
    {
        if (s[1] == t[1] && s[2] == t[2])
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }

        return;
    }
    if (s == t)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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