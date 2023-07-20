#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int l, r, x, a, b;
    cin >> l >> r >> x >> a >> b;
    if (a > b)
        swap(a, b);
    if (a == b)
    {
        cout << 0 << endl;
        return;
    }
    if (abs(b - a) >= x)
    {
        cout << 1 << endl;
        return;
    }
    if (abs(r - a) >= x && abs(r - b) >= x)
    {
        cout << 2 << endl;
        return;
    }
    if (abs(l - a) >= x && abs(l - b) >= x)
    {
        cout << 2 << endl;
        return;
    }
    if (abs(r - a) >= x && abs(r - l) >= x && abs(l - b) >= x)
    {
        cout << 3 << endl;
        return;
    }
    if (abs(l - a) >= x && abs(r - l) >= x && abs(r - b) >= x)
    {
        cout << 3 << endl;
        return;
    }

    cout << -1 << endl;
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