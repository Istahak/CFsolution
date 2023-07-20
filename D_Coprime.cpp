#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
void solve()
{
    int n;
    cin >> n;
    map<int, int> mp;
    int ans = -1;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            ans = max(ans, i + mp[x]);
        }
        mp[x] = max(mp[x], i);
    }
    for (auto a : mp)
    {
        for (auto b : mp)
        {
            if (__gcd(a.first, b.first) == 1)
            {
                ans = max(ans, a.second + b.second);
            }
        }
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
