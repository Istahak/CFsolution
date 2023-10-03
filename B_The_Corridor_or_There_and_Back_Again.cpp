#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (auto &[x, y] : v)
        cin >> x >> y;

    int ans = INT_MAX;
    for (auto [x, y] : v)
    {
        ans = min(ans, x + (y - 1) / 2);
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