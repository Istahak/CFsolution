#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        mp[i] = n + 1;
    }
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        int mx = max(x, y);
        int mi = min(x, y);

        if (mp[mi] > mx)
        {
            mp[mi] = mx;
        }
    }
    int cnt = n + 1;
    ll ans = 0;
    for (int i = n; i >= 1; i--)
    {
        cnt = min(cnt, mp[i]);
        int x = cnt - i;
        ans += x;
    }
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