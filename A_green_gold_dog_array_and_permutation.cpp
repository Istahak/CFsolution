#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        auto &[x, y] = v[i];
        cin >> x;
        y = i;
    }
    sort(v.rbegin(), v.rend());
    vector<int> ans(n);
    int cur = 1;
    for (auto [x, y] : v)
    {
        ans[y] = cur++;
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
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}