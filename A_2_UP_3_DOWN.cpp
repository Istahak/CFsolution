#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int x, y;
    cin >> x >> y;
    if (x > y)
    {
        if ((x - y) <= 3)
        {
            cout << "Yes" << '\n';
        }
        else
        {
            cout << "No" << '\n';
        }
    }
    else
    {
        if ((y - x) <= 2)
        {
            cout << "Yes" << '\n';
        }
        else
        {
            cout << "No" << '\n';
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}