#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    sort(v.rbegin(), v.rend());
    ll sum = accumulate(v.begin(), v.end(), 0LL);
    ll fix = (sum + n - 1) / n;

    ll ans = sum;
    ll cur = 0, li = 0;
    for (int i = 0; i < n; i++)
    {
        cur += v[i];
        sum -= v[i];
        if (cur > sum)
        {
            li = (cur - sum + 1) / 2;
        }
        ans = min(ans, i + 1 + sum + li);
        li = 0;
    }
    cout << ans << '\n';
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