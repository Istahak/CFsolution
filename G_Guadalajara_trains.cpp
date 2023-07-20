#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<ll> dis(n + 1, 0), time;
    for (int i = 1; i < n; i++)
        cin >> dis[i];
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        time.push_back(x);
        if (i != n)
            time.push_back(dis[i]);
    }
    int sz = time.size();
    vector<ll> prel(sz, 0), prer(sz, 0);
    prel[0] = time[0];
    for (int i = 1; i < sz; i++)
    {
        prel[i] = prel[i - 1] + time[i];
    }
    prer[sz - 1] = time[sz - 1];
    for (int i = sz - 2; i >= 0; i--)
    {
        prer[i] = prer[i + 1] + time[i];
    }
    // for (auto i : time)
    //     cout << i << ' ';
    // cout << endl;
    // for (auto i : prel)
    //     cout << i << ' ';
    // cout << endl;
    // for (auto i : prer)
    //     cout << i << ' ';
    // cout << endl;
    ll ans = 0;
    for (int i = 0; i < sz; i++)
    {
        if (i % 2 == 1)
        {
            if (prel[i] > prer[i])
            {
                ans = time[i-1] - abs(prel[i-1] - prer[i-1]);
                break;
            }
        }
        if (i % 2 == 0)
        {
            if (prel[i] > prer[i])
                break;
        }
    }
    cout << max(0ll,ans) << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    // cin >> tt;
    while (tt--)
        solve();

    return 0;
}