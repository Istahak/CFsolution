#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    ll oddsum = 0, evensum = 0;
    ll mx = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if (i & 1)
        {
            if (x > 0)
            {
                oddsum += x;
            }
        }
        else
        {
            if (x > 0)
            {
                evensum += x;
            }
        }
        mx = max(mx, x);
    }
    if (mx < 0)
    {
        cout << mx << endl;
        return;
    }
    cout << max({mx, evensum, oddsum}) << endl;
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