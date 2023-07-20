#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    if (n < 0)
        n = -n;
    if (m < 0)
        m = -m;
    if (m == n)
    {
        cout << m * 2 << endl;
    }
    else
    {
        int mx = max(n, m);
        cout << mx * 2 - 1 << endl;
    }
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