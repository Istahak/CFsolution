#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        v[i] %= k;
    }
    if (count(v.begin(), v.end(), 0) == n)
    {
        cout << 0 << endl;
        return;
    }
    map<int, int> mp;
    for (auto x : v)
    {
        if (x == 0)
            continue;
        mp[k - x]++;
    }
    ll ans = 0;
    for (auto [x, y] : mp)
    {

        ans = max(ans, x*1LL + (y - 1) * k * 1LL);
    }
    cout << ans + 1 << endl;
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