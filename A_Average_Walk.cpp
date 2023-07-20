#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int x;
    cin >> x;
    if (3000 % x == 0)
        x = 3000 / x;
    else
        x = 3000 / x + 1;
    cout << min(x, 15) << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    // cin >> tt;
    while (tt--)
        solve();

    return 0;
}