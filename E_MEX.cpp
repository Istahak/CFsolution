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
    string s;
    cin >> s;
    vector<vector<ll>> prefix(n, vector<ll>(3, 0));
    vector<vector<ll>> suffix(n, vector<ll>(3, 0));
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'M')
            prefix[i][v[i]]++;
        if (s[i] == 'X')
            suffix[i][v[i]]++;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            prefix[i][j] += prefix[i - 1][j];
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < 3; j++)
        {
            suffix[i][j] += suffix[i + 1][j];
        }
    }
    auto f = [&](int x, int y, int z)
    {
        for (int i = 0; i <= 2; i++)
        {
            if (x == i or y == i or z == i)
                continue;
            else
                return i;
        }
        return 3;
    };
    ll ans = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (s[i] != 'E')
            continue;
        for (int k = 0; k <= 2; k++)
        {
            for (int l = 0; l <= 2; l++)
            {
                ll mex = f(k, v[i], l);
                ans += (prefix[i - 1][k] * suffix[i + 1][l]) * mex;
            }
        }
    }
    cout << ans << '\n';
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