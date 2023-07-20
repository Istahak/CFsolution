#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int x = 1, y = n * n, cnt = 1;
    int arr[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {

            if (cnt & 1)
            {
                arr[i][j] = x;
                x++;
                cnt++;
            }
            else
            {
                arr[i][j] = y;
                y--;
                cnt++;
            }
        }
    }
    for (int i = n; i >= 1; i--)
    {
        if (i & 1)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << arr[i][j] << ' ';
            }
        }
        else
        {
            for (int j = n; j >= 1; j--)
            {
                cout << arr[i][j] << ' ';
            }
        }
        cout << endl;
    }
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