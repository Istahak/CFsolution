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
    vector<pair<int, int>> ans;
    int mi = *min_element(v.begin(), v.end());
    int mx = *max_element(v.begin(), v.end());
    if (mx <= 0)
    {
        for (int i = n - 1; i > 0; i--)
        {
            v[i - 1] += v[i];
            ans.push_back({i, i + 1});
        }
    }
    else
    {
        int id = max_element(v.begin(), v.end()) - v.begin();
        while (v[id] < (-mi))
        {
            v[id] += v[id];
            ans.push_back({id + 1, id + 1});
        }
        for (int i = 0; i < n; i++)
        {
            if (v[i] < 0)
            {
                v[i] += v[id];
                ans.push_back({i + 1, id + 1});
            }
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (v[i] > v[i + 1])
            {
                v[i + 1] += v[i];
                ans.push_back({i + 1 + 1, i + 1});
            }
        }
    }
   
    cout << ans.size() << endl;
    for (auto [x, y] : ans)
    {
        cout << x << ' ' << y << endl;
    }
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