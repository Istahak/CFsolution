#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    ll n, w;
    cin >> n >> w;
    ll mx = 0, mn = 0;
    ll sum = 0, x;
    for (int i = 0; i < n; i++)
        cin >> x, sum += x, mn = min(mn, sum), mx = max(mx, sum);
    cout << max(0LL, w - mx + mn + 1) << endl;
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