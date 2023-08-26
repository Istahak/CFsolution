#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;
    if (!is_sorted(v.begin(), v.end()))
    {
        cout << 0 << endl;
        return;
    }
    int ans = 1e9;
    for (int i = 0; i < n - 1; i++)
    {
        ans = min(ans, (v[i + 1] - v[i]) / 2 + 1);
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