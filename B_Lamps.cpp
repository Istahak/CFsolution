#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;

    map<int, priority_queue<int>> mp;
    for (int i = 1; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        mp[x].emplace(y);
    }
    ll ans = 0;
    for (auto [x, pq] : mp)
    {
        int y = x;
        for (int i = 0; i < y and !pq.empty(); i++)
        {
            ans += pq.top();
            pq.pop();
        }
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