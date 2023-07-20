#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    ll arr[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    if ((n + m - 1) & 1)
    {
        cout << "NO" << endl;
        return;
    }
    ll mi[n][m], mx[n][m];
    mi[0][0] = arr[0][0], mx[0][0] = arr[0][0];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (i > 0 && j > 0)
            {
                mi[i][j] = min(mi[i - 1][j], mi[i][j - 1]) + arr[i][j];
                mx[i][j] = max(mx[i - 1][j], mx[i][j - 1]) + arr[i][j];
            }
            else if (i > 0)
            {
                mi[i][j] = mi[i - 1][j] + arr[i][j];
                mx[i][j] = mx[i - 1][j] + arr[i][j];
            }
            else if (j > 0)
            {
                mi[i][j] = mi[i][j - 1] + arr[i][j];
                mx[i][j] = mx[i][j - 1] + arr[i][j];
            }
        }

    cout << ((mi[n - 1][m - 1] <= 0 && mx[n - 1][m - 1] >= 0) ? "YES" : "NO") << endl;
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
