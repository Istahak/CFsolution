#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        v[x].push_back(i);
    }
    ll ans = 0;
    for (auto vv : v)
    {
        if (vv.size() <= 1)
            continue;
        ll cnt = 1;
        for (int i = 1; i < vv.size(); i++)
        {
            ans += (vv[i] - vv[i - 1] - 1) * (cnt) * (vv.size() - cnt);
            cnt++;
        }
    }
    cout << ans << endl;
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