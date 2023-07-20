#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    ll x, k;
    cin >> x >> k;
    if (x % k == 0)
    {
        cout << 2 << endl;
        cout << 1 << ' ' << x - 1 << endl;
    }
    else
    {
        cout << 1 << endl;
        cout << x << endl;
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
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}