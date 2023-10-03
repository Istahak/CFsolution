#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    ll n, m;
    cin >> n >> m;
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll abnormal = x2 - x1 + 1;
    ll normal = n - abnormal;
    ll ans = (m % 2) * normal;
    ans += ((y1 - 1) % 2) * abnormal;
    ans += ((m - y2) % 2) * abnormal;
    cout << (ans + 1) / 2 << endl;
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