#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    int x, y, p, q;
    cin >> x >> y >> p >> q;
    auto ans = [&](int x, int y)
    {
        if (x == 1 && y == 1)
        {
            return 2;
        }
        if (x == 1 && y == m)
        {
            return 2;
        }
        if (x == n && y == m)
        {
            return 2;
        }
        if (x == n && y == 1)
        {
            return 2;
        }
        if (x == 1 || y == 1 || x == n || y == m)
        {
            return 3;
        }
        return 4;
    };
    cout << min(ans(x, y), ans(p, q)) << endl;
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