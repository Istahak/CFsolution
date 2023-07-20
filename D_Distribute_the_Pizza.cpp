#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int r, h;
    cin >> r >> h;
    int n = 360 / h;
    cout << ((n & 1) ? "NO" : "YES") << endl;
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
