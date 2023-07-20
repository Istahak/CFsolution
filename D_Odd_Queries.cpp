#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<ll> v(n + 1);
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }
    for (int i = 1; i <= n; i++)
        v[i] += v[i - 1];
    // for (auto x : v)
    //     cout << x << ' ';
    // cout << endl;

    while (q--)
    {
        int l, r, x;
        cin >> l >> r >> x;
        ll ans = sum - (v[r] - v[l - 1]);
        ans += (r - l + 1) * x;
        if (ans & 1)
        {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }
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
