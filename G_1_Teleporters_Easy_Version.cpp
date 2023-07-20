#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        v[i] += (i + 1);
    }
    sort(v.begin(), v.end());
    vector<ll> pre(n, 0);
    pre[0] = v[0];
    for (int i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] + v[i];
    }
    ll l = 0, r = n - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (pre[mid] <= k)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << l << endl;
    // auto it = lower_bound(pre.begin(), pre.end(), k) - pre.begin();
    // cout << it << endl;
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