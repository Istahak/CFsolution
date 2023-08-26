#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    vector<int> a(n);
    vector<int> b(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    for (int i = 0; i < n; i++)
    {
        v[i].first = a[i] - b[i];
        v[i].second = i;
    }
    sort(v.rbegin(), v.rend());
    vector<int> ans;
    int xx = v[0].first;
    for (auto [x, y] : v)
    {
        if (x == xx)
        {
            ans.push_back(y);
        }
    }
    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for (auto x : ans)
        cout << x + 1 << ' ';
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