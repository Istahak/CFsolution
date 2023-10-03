#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    char g[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
        }
    }
    vector<vector<int>> L(m);
    vector<vector<int>> U(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == 'L')
            {
                L[j].push_back(i);
            }
            if (g[i][j] == 'U')
            {
                U[i].push_back(j);
            }
        }
    }

    for (auto x : L)
    {
        int sz = x.size();
        if (sz % 2 == 1)
        {
            cout << -1 << endl;
            return;
        }
    }

    for (auto x : U)
    {
        int sz = x.size();
        if (sz % 2 == 1)
        {
            cout << -1 << endl;
            return;
        }
    }

    char ans[n + 2][m + 2];

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         if (g[i][j] == '.')
    //         {
    //             ans[i][j] = '.';
    //         }
    //         else
    //         {
    //             if (ans[i][j] == 'W' or ans[i][j] == 'B')
    //                 continue;
    //             int p = 0;
    //             if (g[i][j] == 'L')
    //             {
    //                 for (auto x : L[j])
    //                 {
    //                     ans[x][j] = (p == 1 ? 'W' : 'B');
    //                     ans[x][j + 1] = (p == 1 ? 'B' : 'W');
    //                     p ^= 1;
    //                 }
    //             }
    //             p = 0;
    //             if (g[i][j] == 'U')
    //             {
    //                 for (auto x : U[i])
    //                 {
    //                     ans[i][x] = (p == 1 ? 'W' : 'B');
    //                     ans[i + 1][x] = (p == 1 ? 'B' : 'W');
    //                     p ^= 1;
    //                 }
    //             }
    //         }
    //     }
    // } for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         if (g[i][j] == '.')
    //         {
    //             ans[i][j] = '.';
    //         }
    //         else
    //         {
    //             if (ans[i][j] == 'W' or ans[i][j] == 'B')
    //                 continue;
    //             int p = 0;
    //             if (g[i][j] == 'L')
    //             {
    //                 for (auto x : L[j])
    //                 {
    //                     ans[x][j] = (p == 1 ? 'W' : 'B');
    //                     ans[x][j + 1] = (p == 1 ? 'B' : 'W');
    //                     p ^= 1;
    //                 }
    //             }
    //             p = 0;
    //             if (g[i][j] == 'U')
    //             {
    //                 for (auto x : U[i])
    //                 {
    //                     ans[i][x] = (p == 1 ? 'W' : 'B');
    //                     ans[i + 1][x] = (p == 1 ? 'B' : 'W');
    //                     p ^= 1;
    //                 }
    //             }
    //         }
    //     }
    // }

    for (int j = 0; j < m; j++)
    {
        for (int u = 0; u < L[j].size(); u += 2)
        {
            int f = L[j][u];
            int s = L[j][u + 1];
            g[f][j] = 'W';
            g[f][j + 1] = 'B';
            g[s][j] = 'B';
            g[s][j + 1] = 'W';
        }
    }

    for (int j = 0; j < n; j++)
    {
        for (int u = 0; u < U[j].size(); u += 2)
        {
            int f = U[j][u];
            int s = U[j][u + 1];
            g[j][f] = 'W';
            g[j + 1][f] = 'B';
            g[j][s] = 'B';
            g[j + 1][s] = 'W';
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << g[i][j];
        }
        cout << endl;
    }
}
int main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}