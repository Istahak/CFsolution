#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    ll n;
    cin >> n;
    ll ans = ((n * (n - 1) * (n - 2)) / 6);
    vector<ll> x(n), y(n), frx(n + 1), fry(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
        frx[x[i]]++;
        fry[y[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        ans -= ((frx[x[i]] - 1) * (fry[y[i]] - 1));
    }
    cout << ans << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    cin >> t;
    while (t--)
    {

        solve();
    }

    return 0;
}