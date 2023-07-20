#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    ll n, x1, x2, y1, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    x1 = min(x1, n - x1 + 1);
    ll a, b;
    if (y1 < x1)
    {
        a = y1;
    }
    else if (y1 > (n - (x1 - 1)))
    {
        a = n - y1 + 1;
    }
    else
    {
        a = x1;
    }
    x2 = min(x2, n - x2 + 1);
    if (y2 < x2)
    {
        b = y2;
    }
    else if (y2 > (n - (x2 - 1)))
    {
        b = n - y2 + 1;
    }
    else
    {
        b = x2;
    }
    cout << abs(a - b) << endl;
}
int main()
{

    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }

    return 0;
}