#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int M = 998244353;
ll l, r;
ll ok(ll mid)
{
    ll cnt = 0;
    for (ll i = mid; i <= r; i *= 2)
    {
        cnt++;
    }
    return cnt;
}
ll ok2(ll mid)
{
    ll cnt = 1;
    ll i = mid;
    for (i = (i)*3ll; i <= r; i *= 2)
    {
        cnt++;
    }
    return cnt;
}
void solve()
{
    cin >> l >> r;
    ll mxsz = 0;
    for (ll i = l; i <= r; i *= 2)
    {
        mxsz++;
    }
    cout << mxsz << ' ';
    ll f = 0;
    ll c = 0;
    ll start = l, end = r;
    while (end >= start)
    {
        ll mid = (start + end) / 2;
        if (ok(mid) == mxsz)
        {
            f = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    start = l, end = r;
    while (end >= start)
    {
        ll mid = (start + end) / 2;
        if (ok2(mid) == mxsz)
        {
            c = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    f = f - l + 1;
    if (c == 0)
        c = 0;
    else
        c = c - l + 1;

    ll ans = (((c % M) * (mxsz % M)) + (f - c) % M) % M;
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