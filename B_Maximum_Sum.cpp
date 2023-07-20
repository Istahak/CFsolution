#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<ll> v(n);
    ll sum = 0;
    for (auto &i : v)
        cin >> i, sum += i;
    sort(v.begin(), v.end());
    vector<ll> prefix(n + 1, 0);
    prefix[0] = v[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + v[i];
    }
    // for (int i = 0; i < n; i++)
    //     cout << prefix[i] << ' ';
    // cout << endl;
    ll ans = LLONG_MIN;
    for (int i = 0; i <= k; i++)
    {
        int x = n - i - 1;
        int y = 2 * (k - i);
        if (y == 0)
        {
            ans = max(ans, prefix[x]);
            continue;
        }
        ll cursum = prefix[x] - prefix[y - 1];
        ans = max(ans, cursum);
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