#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, m, d;
    cin >> n >> m >> d;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        auto &[x, y] = v[i];
        cin >> x;
        y = i;
    }
    sort(v.begin(), v.end());
    vector<int> ans(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(INT_MIN, 1);
    int cur = 1;
    for (auto [t, id] : v)
    {
        auto [x, y] = pq.top();
        if (x + d >= t)
        {
            cur++;
            pq.emplace(INT_MIN, cur);
        }
        auto p = pq.top();
        pq.pop();
        auto &[xx, yy] = p;
        ans[id] = yy;
        xx = t;
        pq.emplace(p);
    }
    cout << *max_element(ans.begin(), ans.end()) << endl;
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