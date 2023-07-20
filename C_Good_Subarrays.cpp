#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    vector<ll> v(n + 1);
    for (int i = 0; i < n; i++)
    {
        v[i + 1] = s[i] - '0' - 1;
    }
    ll ans = 0;
    ll currsum = 0;
    map<ll, ll> presum;
    for (int i = 1; i <= n; i++)
    {
        currsum += v[i];
        if (currsum == 0)
            ans++;
        ans += presum[currsum];
        presum[currsum]++;
    }
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