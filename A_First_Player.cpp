#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif

void solve()
{
    int n;
    cin >> n;
    int mx = INT_MAX, pos = -1;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        string s;
        int x;
        cin >> s >> x;
        v[i] = s;
        if (mx > x)
        {
            mx = x, pos = i;
        }
    }
    // debug(),dbg(pos);
    for (int i = pos; i < n; i++)
        cout << v[i] << '\n';
    for (int i = 0; i < pos; i++)
        cout << v[i] << '\n';
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