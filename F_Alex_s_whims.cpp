#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif

void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n - 1; i++)
    {
        cout << i << ' ' << i + 1 << '\n';
    }
    int cur = n - 1;
    while (q--)
    {
        int s;
        cin >> s;
        if (cur == s)
        {
            cout << "-1 -1 -1" << '\n';
            continue;
        }
        cout << n << ' ' << cur << ' ' << s << '\n';
        cur = s;
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
        // cout << "Case " << cs << ": ";
        solve();
    }
    return 0;
}