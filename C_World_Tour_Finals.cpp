#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> val(m + 1);
    vector<pair<int, int>> result, vaa;
    for (int i = 1; i <= m; i++)
    {
        cin >> val[i];
        vaa.push_back({val[i], i});
    }
    char grid[n + 1][m + 1];
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'o')
            {
                cnt += val[j];
            }
        }
        result.push_back({cnt + i, i});
    }
    sort(result.rbegin(), result.rend());
    // for (auto [x, y] : result)
    //     cout << y << ' ' << x << '\n';
    sort(vaa.rbegin(), vaa.rend());
    vector<int> ans(n + 1);
    int mx = result[0].first;
    // cout << mx << '\n';
    for (auto [x, id] : result)
    {
        if (mx > x)
        {
            int cnt = 0;
            for (auto [p, q] : vaa)
            {
                if (grid[id][q] == 'x')
                    x += p, cnt++;
                if (x >= mx)
                    break;
            }
            ans[id] = cnt;
        }
        else
        {
            ans[id] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << '\n';
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