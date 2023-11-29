#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int n, k;
string s, t;
void solve()
{
    cin >> n >> k;
    cin >> s >> t;
    vector<int> cnts(26, 0);
    vector<int> cntt(26, 0);
    for (auto x : s)
        cnts[x - 'a']++;
    for (auto x : t)
    {
        cntt[x - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (cntt[i])
        {
            if (cnts[i] == 0)
            {
                cout << "No" << '\n';
                return;
            }
        }
    }
    bool ok = true;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != t[i])
        {
            if (i - k+1 < 0 && i + k+1 >= n)
                ok = false;
        }
    }
    cout << (ok ? "Yes" : "No") << endl;
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