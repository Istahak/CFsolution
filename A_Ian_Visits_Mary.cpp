#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int x, y;
    cin >> x >> y;

    cout << 2 << endl;
    cout << x - 1 << ' ' << 1 << endl;
    cout << x << ' ' << y << endl;
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