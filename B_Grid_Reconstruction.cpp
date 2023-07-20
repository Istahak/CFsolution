#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int arr[3][n + 1];
    int x = 2 * n;
    int y = 2;
    for (int i = 1; i <= n; i++)
    {
        if (i & 1)
        {
            arr[1][i] = x;
            x -= 2;
        }
        else
        {
            arr[1][i] = y;
            y += 2;
        }
    }
    x = 2 * n - 1, y = 1;
    for (int i = 1; i <= n; i++)
    {
        if (i & 1)
        {
            arr[2][i] = y;
            y += 2;
        }
        else
        {
            arr[2][i] = x;
            x -= 2;
        }
    }
    swap(arr[2][2], arr[2][n]);
    for (int i = 1; i <= 2; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
}
int main()
{

    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }

    return 0;
}