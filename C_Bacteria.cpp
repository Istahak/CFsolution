#include <bits/stdc++.h>
#define ll __int128_t
#define lll long long int
using namespace std;
void solve()
{
    lll n;
    cin >> n;
    vector<lll> v(n);
    for (auto &x : v)
        cin >> x;
   
    sort(v.rbegin(), v.rend());
    bool flag = true;
    int mi = v.back();
    for (auto x : v)
    {
        if (x % mi == 0)
        {
            x /= mi;
            if (x & (x - 1))
            {
                cout << -1 << endl;
                return;
            }
        }
        else
        {
            cout << -1 << endl;
            return;
        }
    }
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (auto &x : v)
    {
        pq.emplace(x);
    }
    lll ans = 0;
    while (pq.size() > 1)
    {
        auto cur = pq.top();
        pq.pop();
        auto curs = pq.top();
        pq.pop();
        if (cur == curs)
        {
            pq.emplace(2 * cur);
        }
        else
        {
            ans++;
            pq.emplace(2 * cur);
            pq.emplace(curs);
        }
    }
    cout << ans << endl;
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