#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;
    priority_queue<ll> pq;
    for (int i = 1; i < n; i++)
    {
        pq.emplace(abs(v[i] - v[i - 1]));
    }
    while (!pq.empty() and k > 1)
    {
        pq.pop();
        k--;
    }
    ll ans = 0;
    while (!pq.empty())
    {
        ans += pq.top();
        pq.pop();
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