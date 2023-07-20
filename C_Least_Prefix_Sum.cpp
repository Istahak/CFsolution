#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<ll> v(n + 1), pre(n + 1, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    ll sum = 0, cnt = 0, store = 0;
    priority_queue<int, vector<int>, greater<int>> pp;
    for (int i = m; i < n; i++)
    {
        if (v[i] < 0)
            pp.push(v[i]);
        sum += v[i];
        while (sum < 0)
        {

            int x = pp.top();
            x = -x;
            sum += (2 * x);
            pp.pop();
            cnt++;
        }
    }
    if (v[m - 1] <= 0)
        store = v[m - 1];
    else if (m != 1)
    {
        store = -v[m - 1];
        cnt++;
    }
    priority_queue<int> pq;
    for (int i = m - 2; i >= 1; i--)
    {
        if (v[i] > 0)
            pq.push(v[i]);
        store += v[i];
        while (store > 0)
        {

            int x = pq.top();
            x = -x;
            store += (2 * x);
            pq.pop();
            cnt++;
        }
    }

    cout << cnt << endl;
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