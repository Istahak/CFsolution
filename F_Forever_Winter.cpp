#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> d(n + 1, 0);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        d[u]++, d[v]++;
    }
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        mp[d[i]]++;
    }
    int xx = -1;
    for (auto [x, y] : mp)
    {
        if (y == 1)
        {
            xx = x;
        }
    }
    cout << xx << endl;
    sort(d.rbegin(), d.rend());
    int yy = -1;
    if (xx == -1)
    {
        xx = d[0];
        yy = d[0];
    }
    if (yy == -1)
    {
        for (int i = 0; i <= n; i++)
        {
            if (xx != d[i])
            {
                yy = d[i];
                break;
            }
        }
    }

    cout << xx << ' ' << yy - 1 << endl;
    // cout << d[0] << ' ' << d[1] - 1 << endl;
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