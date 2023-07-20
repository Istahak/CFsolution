#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, q, k;
    cin >> n >> k >> q;
    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;
    ll cnt = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] <= q)
        {
            cnt++;
            if (cnt >= k)
            {
                ans += (cnt - k + 1);
            }
        }
        else
        {
            cnt = 0;
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