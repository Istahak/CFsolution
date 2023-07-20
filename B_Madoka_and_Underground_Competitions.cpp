#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n, k, r, c;
    cin >> n >> k >> r >> c;
    char arr[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            arr[i][j] = '.';

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)

        {
            if (!(((i + j) - (r + c)) % k))
                arr[i][j] = 'X';
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << arr[i][j];
        cout << endl;
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