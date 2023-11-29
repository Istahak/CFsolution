#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<ll> cuxor(2 * n + 1, 0);
    cuxor[0]++;

    ll cur = 0;
    ll extra = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cur ^= x;
        for (ll j = 0; j * j < 2 * n; j++)
        {
            if ((cur ^ (j * j)) < 2 * n)
                extra += cuxor[cur ^ (j * j)];
        }
        cuxor[cur]++;
    }
    ll ans = n * 1ll * (n + 1);
    ans >>= 1;

    cout << ans - extra << '\n';
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