#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n, m, cnt = 0;
    cin >> n >> m;
    char arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == '1')
                cnt++;
        }
    }
    if (cnt == 0)
    {
        cout << 0 << endl;
        return;
    }
    bool flag1 = false, flag2 = false, flag3 = false, flag4 = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x = 0;
            if (i != 0 && j != 0)
            {
                if (arr[i][j] == '1')
                    x++;
                if (arr[i][j - 1] == '1')
                    x++;
                if (arr[i - 1][j] == '1')
                    x++;
            }
            if (i != 0 && j != 0)
            {
                if (x == 0)
                    flag1 = true;
                if (x == 1)
                    flag2 = true;
                if (x == 2)
                    flag3 = true;
                if (x == 3)
                    flag4 = true;
            }

            x = 0;
            if (j != (m - 1) && i != 0)
            {
                if (arr[i][j] == '1')
                    x++;
                if (arr[i][j + 1] == '1')
                    x++;
                if (arr[i - 1][j] == '1')
                    x++;
            }
            if (j != (m - 1) && i != 0)
            {
                if (x == 0)
                    flag1 = true;
                if (x == 1)
                    flag2 = true;
                if (x == 2)
                    flag3 = true;
                if (x == 3)
                    flag4 = true;
            }

            x = 0;
            if (j != 0 && i != (n - 1))
            {
                if (arr[i][j] == '1')
                    x++;
                if (arr[i][j - 1] == '1')
                    x++;
                if (arr[i + 1][j] == '1')
                    x++;
            }
            if (j != 0 && i != (n - 1))
            {
                if (x == 0)
                    flag1 = true;
                if (x == 1)
                    flag2 = true;
                if (x == 2)
                    flag3 = true;
                if (x == 3)
                    flag4 = true;
            }

            x = 0;
            if (j != (m - 1) && i != (n - 1))
            {
                if (arr[i][j] == '1')
                    x++;
                if (arr[i][j + 1] == '1')
                    x++;
                if (arr[i + 1][j] == '1')
                    x++;
            }
            if (j != (m - 1) && i != (n - 1))
            {
                if (x == 0)
                    flag1 = true;
                if (x == 1)
                    flag2 = true;
                if (x == 2)
                    flag3 = true;
                if (x == 3)
                    flag4 = true;
            }
        }
    }

    if (flag1)
    {
        cout << cnt << endl;
        return;
    }
    if (flag2)
    {
        cout << cnt << endl;
        return;
    }
    if (flag3)
    {
        cout << cnt - 1 << endl;
        return;
    }
    if (flag4)
    {
        cout << cnt - 2 << endl;
        return;
    }
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