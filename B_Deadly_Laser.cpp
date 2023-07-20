#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n, m, x, y, d;
    cin >> n >> m >> x >> y >> d;
    int ax = n - 1;
    int ay = m - 1;
    if ((x + d >= n && x - d <= 1) || (y + d >= m && y - d <= 1))
    {
        cout << -1 << endl;
        return;
    }

    if ((x - d <= 1 && y - d <= 1) || (x + d >= n && y + d >= m))
    {
        cout << -1 << endl;
        return;
    }

    cout << ax + ay << endl;
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