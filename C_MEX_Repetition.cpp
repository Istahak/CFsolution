#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    char arr[n][m];
    char brr[n][m];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> arr[i][j];
        }
    }
    int column[m];
    int row[n];
    memset(column, 0, sizeof(column));
    memset(row, 0, sizeof(row));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (arr[i][j] == '.')
            {
                brr[i][j] = '.';
                continue;
            }
            if (brr[i][j] == 'W' || brr[i][j] == 'B')
                continue;
            if (arr[i][j] == 'L')
            {
                if (column[j] >= 0)
                {
                    column[j]--;
                    column[j + 1]++;
                    brr[i][j] = 'W';
                    brr[i][j + 1] = 'B';
                }
                else
                {
                    column[j]++;
                    column[j + 1]--;
                    brr[i][j] = 'B';
                    brr[i][j + 1] = 'W';
                }
            }
            if (arr[i][j] == 'U')
            {
                if (row[i] >= 0)
                {
                    row[i]--;
                    row[i + 1]++;
                    brr[i][j] = 'W';
                    brr[i + 1][j] = 'B';
                }
                else
                {
                    row[i]++;
                    row[i + 1]--;
                    brr[i][j] = 'B';
                    brr[i + 1][j] = 'W';
                }
            }
        }
    }
    for (int i = 0; i < m; ++i)
    {
        if (column[i] != 0)
        {
            cout << -1 << endl;
            return;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (row[i] != 0)
        {
            cout << -1 << endl;
            return;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << brr[i][j];
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