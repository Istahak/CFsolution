#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    int y = n - m;
    for (int cur = 1; cur <= n; cur++)
    {
        int p = (m + cur - 1) / cur;
        if (y >= (p - 1))
        {
            cout << m << ' ' << min(m, cur) << endl;
            return;
        }
    }
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