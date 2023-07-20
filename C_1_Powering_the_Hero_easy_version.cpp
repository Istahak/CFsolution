#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    priority_queue<ll> pq;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if (x == 0)
        {
            if (!pq.empty())
            {
                int y = pq.top();
                pq.pop();
                ans += y;
            }
        }
        else
        {
            pq.push(x);
        }
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}