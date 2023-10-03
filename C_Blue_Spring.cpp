#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    ll d, p;
    cin >> n >> d >> p;
    priority_queue<ll> pq;
    ll rm = (d + p - 1) / d;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;

        pq.emplace(x);
    }
    ll curcost = 0;
    int curp = 0;
    while (!pq.empty())
    {
        curcost += pq.top();
        pq.pop();
        curp++;
        if (curp == d)
        {
            curp = 0;
            if (p <= curcost)
            {
                ans += p;
            }
            else
            {
                ans += curcost;
            }
            curcost = 0;
        }
    }
    if (curcost)
    {
        if (curcost <= p)
        {
            ans += curcost;
        }
        else
        {
            ans += p;
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