#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif
int f(int a, int b, int c)
{
    int m = min(b, c);
    a += m;
    b -= m;
    c -= m;
    return (b % 2 == 0 and c % 2 == 0);
}
void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << f(a, b, c) << ' ' << f(b, a, c) << ' ' << f(c, a, b) << '\n';
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