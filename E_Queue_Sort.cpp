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
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;
    int val = -1, pos = 0;
    for (int i = n - 1; i >= 1; i--)
    {
        if (v[i] < v[i - 1])
        {
            val = v[i];
            pos = i;
            break;
        }
    }
    if (pos == 0)
    {
        cout << 0 << '\n';
        return;
    }

    for (int i = 0; i < pos; i++)
    {
        if (v[i] <= val)
        {
            cout << -1 << '\n';
            return;
        }
    }
    cout << pos << '\n';
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