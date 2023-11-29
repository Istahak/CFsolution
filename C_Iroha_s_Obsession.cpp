#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(10);
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        v[x] = 1;
    }
    while (1)
    {
        int k = n;
        bool ok = true;
        while (k)
        {
            if (v[k % 10])
                ok = false;
            k /= 10;
        }
        if (ok)
        {
            cout << n << '\n';
            return;
        }
        n++;
    }
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