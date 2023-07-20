#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ans ^= x;
    }
    if (~n & 1)
    {
        if (ans != 0)
        {
            cout << -1 << endl;
            return;
        }
    }
     cout << ans << endl;
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