#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif

void solve()
{
    string s;
    cin >> s;
    for (int i = 0; i < (int)s.size() - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            cout << i + 1 << " " << i + 2;
            return;
        }
    }
    for (int i = 0; i < (int)s.size() - 2; i++)
    {
        if (s[i] == s[i + 2])
        {
            cout << i + 1 << " " << i + 3;
            return;
        }
    }
    cout << "-1 -1";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case " << cs << ": ";
        solve();
    }
    return 0;
}