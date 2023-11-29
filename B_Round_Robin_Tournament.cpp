#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    char grid[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> grid[i][j];
        }
    }
    vector<pair<int, int>> cnt;
    for (int i = 1; i <= n; i++)
    {
        int cn = 0;
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            if (grid[i][j] == 'o')
                cn++;
        }
        cnt.push_back({cn, -i});
    }
    sort(cnt.rbegin(), cnt.rend());
    for (auto [x, y] : cnt)
    {
        cout << (-y) << ' ';
    }
    cout << '\n';
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