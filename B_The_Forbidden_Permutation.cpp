#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> p(n + 1), a(m + 1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        p[x] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i];
    }
    int ans = INT_MAX;
    int f = 0;
    for (int i = 1; i < m; i++)
    {
        int ps = p[a[i]];
        int ps2 = p[a[i + 1]];
        if (ps >= ps2)
        {
            ans = 0;
            break;
        }
        if (ps2 > ps + d)
        {
            ans = 0;
            break;
        }
        ans = min(ans, ps2 - ps);
        int x = d + 1 - (ps2 - ps);
        int y = n - ps2 + ps - 1;
        if (x <= y)
        {
            ans = min(ans, d + 1 - (ps2 - ps));
        }
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