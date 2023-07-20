#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    map<int, ll> fr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        fr[x]++;
    }
    ll ans = 0;
    for (auto [x, y] : fr)
    {
        for (ll i = 2; i * i <= x; i++)
        {
            if (x % (i * i) == 0)
            {
                int q = x / i;
                int r = q / i;
                ans += (y * fr[q] * fr[r]);
            }
        }
        if (y > 2)
        {
            ans += (y * (y - 1) * (y - 2));
        }
    }
    cout << ans << endl;
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