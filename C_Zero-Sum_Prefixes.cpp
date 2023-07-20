#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n;
    cin >> n;
    vector<ll> v(n + 1), pre(n + 1, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        pre[i] = pre[i - 1] + v[i];
    }
    map<ll, int> mp;
    int mx = INT_MIN;
    for (int i = n; i > 0; i--)
    {
        mp[pre[i]]++;
        mx = max(mx, mp[pre[i]]);
        if (v[i] == 0)
        {
            ans += mx;
            mx = INT_MIN;
            mp.clear();
        }
    }
    ans += mp[0];
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    cin >> t;
    while (t--)
    {

        solve();
    }

    return 0;
}