#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    ll a, b, n;
    cin >> a >> b >> n;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        sum += min(a, x + 1);
    }
    sum -= n;
    sum += b;
    cout << sum << '\n';
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