#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> r(n), ans(n);
    for (auto &x : r) cin >> x;
    auto f = r; sort(f.begin(), f.end());
    for (int i = 0; i < n; i++)
    {
        ans[i] = lower_bound(f.begin(), f.end(), r[i]) - f.begin();
    }
    while (m--)
    {
        int x, y;
        cin >> x >> y; x--, y--;
        if (r[x] > r[y]) ans[x]--;
        if (r[x] < r[y]) ans[y]--;
    }
    for (auto x : ans)
        cout << x << ' ';
    cout << endl;
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