#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int a, b, c, x;
    cin >> a >> b >> c;
    if (b < c)
    {
        x = (c - b) + c;
    }
    else
    {
        x = b;
    }
    if (a < x)
    {
        cout << 1 << endl;
    }
    else if (a > x)
    {
        cout << 2 << endl;
    }
    else
    {
        cout << 3 << endl;
    }
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