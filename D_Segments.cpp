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
        int x, y;
        cin >> x >> y;
        if (x > y)
            swap(x, y);
        v[i] = {y, x};
    }
    sort(v.begin(), v.end());
    // for (auto [x, y] : v)
    //     cout << x << ' ' << y << endl;
    vector<int> ans;
    for (auto [y, x] : v)
    {
        if (ans.empty())
        {
            ans.push_back(y);
        }
        else
        {
            if (x <= ans.back() and ans.back() <= y)
                continue;
            else
                ans.push_back(y);
        }
    }
    cout << ans.size() << endl;
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