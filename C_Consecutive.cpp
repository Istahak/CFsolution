#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<ll> pre(n + 1, 0);
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i + 1] == s[i])
        {
            pre[i + 1]++;
        }
    }
    for (int i = 1; i <= n; i++)
        pre[i] += pre[i - 1];
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        ll ans = pre[r] - pre[l - 1];
        if (r != n and s[r - 1] == s[r])
            ans--;
        cout << ans << '\n';
    }
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