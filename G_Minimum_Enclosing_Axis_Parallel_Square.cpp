#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    ll xx = x.back() - x[0];
    ll yy = y.back() - y[0];
    ll ans = max(xx, yy);
    cout << ans * ans << endl;
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