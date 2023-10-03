#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    ll n, x, y;
    cin >> n >> x >> y;
    auto div = [&](ll h)
    {
        return h * (h + 1) / 2;
    };
    ll xd = n / x;
    ll yd = n / y;
    ll xyd = n / lcm(x, y);

    xd -= xyd;
    yd -= xyd;
    cout << div(n) - div(n - xd) - div(yd) << endl;
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