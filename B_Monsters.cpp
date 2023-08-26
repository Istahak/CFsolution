#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    priority_queue<pair<int, int>> pq;
    vector<int> ans1;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x % k == 0)
        {
            cout << i << ' ';
        }
        else
            pq.emplace((x % k), -i);
    }
    vector<int> ans;
    while (!pq.empty())
    {
        auto [x, y] = pq.top();
        pq.pop();
        ans.push_back(-y);
    }
    // reverse(ans.begin(), ans.end());
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