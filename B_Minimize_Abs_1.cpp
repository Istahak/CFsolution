#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif

void solve()
{
    int n, L, R;
    cin >> n >> L >> R;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x <= L)
        {
            cout << L << ' ';
        }
        else if (L <= x and x <= R)
        {
            cout << x << ' ';
        }
        else
        {
            cout << R << ' ';
        }
    }
    cout << '\n';
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