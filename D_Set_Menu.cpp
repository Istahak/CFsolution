#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    ll n, m, p;
    cin >> n >> m >> p;
    vector<ll> a(n), b(m);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    auto pre = b;
    for (int i = 1; i < m; i++)
        pre[i] += pre[i - 1];
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ll extra = p - a[i];
        ll l = 0, r = m - 1;
        ll lst = -1;
        while (l <= r)
        {
            int mi = (l + r) / 2;
            if (b[mi] > extra)
            {
                lst = mi;
                r = mi - 1;
            }
            else
                l = mi + 1;
        }
        if (lst == -1)
        {
            ans += pre[m - 1];
            ans += m * a[i];
        }
        else if (lst == 0)
        {
            ans += a[i] * (lst);
            ans += (p * (m - lst));
        }
        else
        {
            ans += pre[lst - 1];
            ans += a[i] * (lst);
            ans += (p * (m - lst));
        }

        // cout << lst << ' ';
    }
    cout << ans << '\n';
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