#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    char g[n + 2][n + 2];
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            cin >> g[i][j];
        }
    }

    int ans = 0;
    vector<vector<int>> maiin(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> add(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> neg(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (add[i][j] != 0)
            {
                maiin[i][j] += add[i][j];
                int l = max(j - 1, 0);
                add[i + 1][l] += add[i][j];
            }
            if (neg[i][j] != 0)
            {
                maiin[i][j] -= neg[i][j];
                int r = min(n, j + 1);
                neg[i + 1][r] += neg[i][j];
            }
        }
        for (int j = 1; j < n; j++)
        {
            maiin[i][j] += maiin[i][j - 1];
        }
        for (int j = 0; j < n; j++)
        {
            if (maiin[i][j] % 2 == 1)
            {
                if (g[i][j] == '0')
                {
                    g[i][j] = '1';
                }
                else
                {
                    g[i][j] = '0';
                }
            }
        }
        for (int j = 0; j < n; j++)
        {
            if (g[i][j] == '1')
            {
                ans += 1;
                int l = max(j - 1, 0);
                int r = min(n, j + 1 + 1);
                add[i + 1][l] += 1;
                neg[i + 1][r] += 1;
            }
        }
    }
    cout << ans << "\n";
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
