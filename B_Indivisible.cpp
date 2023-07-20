#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    if (n & 1)
    {
        cout << -1 << endl;
        return;
    }
    int x = 1, y = 2;
    for (int i = 1; i <= n; i++)
    {
        if (i & 1)
        {
            cout << y << ' ';
            y += 2;
        }
        else
        {
            cout << x << ' ';
            x += 2;
        }
    }
    cout << endl;
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