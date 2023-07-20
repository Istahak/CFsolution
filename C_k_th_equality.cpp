#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int val[] = {0, 1, 10, 100, 1000, 10000, 100000, 1000000};
void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    ll k;
    cin >> k;
    for (int i = val[a]; i < val[a + 1]; i++)
    {
        int mn = max(val[b], val[c] - i);
        int mx = min(val[b + 1] - 1, val[c + 1] - 1 - i);
        int rn = mx - mn + 1;
        if (rn <= 0)
            continue;
        if (rn >= k)
        {
            cout << i << " + " << mn + k - 1 << " = " << i + mn + k - 1 << endl;
            return;
        }
        k -= rn;
    }
    cout << -1 << endl;
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