#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int x;
    cin >> x;
    x *= 2;

    int y = 360 - x;
    int flag = __gcd(x, y);
    x /= flag, y /= flag;
    cout << (y == 1 ? 2 * (x + y) : (x + y)) << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    cin >> t;
    while (t--)
    {

        solve();
    }

    return 0;
}