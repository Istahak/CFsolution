#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve()
{
    int n;
    cin >> n;
    map<pair<int, int>, int> mp;
    int ans1 = 0, ans2 = 0, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        if (x == 0 or y == 0)
        {
            if (x == 0)
                ans1++;
            if (y == 0)
                ans2++;
            if (x == 0 and y == 0)
                cnt++;
            continue;
        }
        int gc = __gcd(x, y);
        x /= gc, y /= gc;
        mp[{x, y}]++;
    }
    int ans = 0;
    for (auto [x, y] : mp)
        ans = max(ans, y + cnt);

    cout << max({ans, ans1, ans2}) << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case " << cs << ": ";
        solve();
    }
    return 0;
}