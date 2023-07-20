#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    if (n & 1)
    {
        cout << -1 << endl;
        return;
    }
    vector<pair<int, int>> ans;

    for (int i = 1; i <= n; i += 2)
    {
        if (v[i] == v[i + 1])
        {
            ans.push_back({i, i + 1});
        }
        else
        {
            ans.push_back({i, i});
            ans.push_back({i + 1, i + 1});
        }
    }
    cout << ans.size() << endl;
    for (auto [x, y] : ans)
        cout << x << ' ' << y << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    cin >> t;
    while (t--)
    {

        solve();
    }

    return 0;
}