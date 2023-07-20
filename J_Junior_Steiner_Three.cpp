#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    char arr[n + 1][m + 1];
    vector<pair<int, int>> v;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == '#')
                v.push_back({i, j});
        }
    int x = v[0].first, y = v[0].second;
    int xx = v[1].first, yy = v[1].second;
    while (x != xx)
    {
        x++;
        arr[x][y] = '#';
    }
    if (y < yy)
    {
        while (y != yy)
        {
            y++;
            arr[x][y] = '#';
        }
    }
    else
    {
        while (y != yy)
        {
            y--;
            arr[x][y] = '#';
        }
    }
    x = v[2].first, y = v[2].second;
    xx = v[1].first, yy = v[1].second;

    while (x != xx)
    {
        x--;
        arr[x][y] = '#';
    }
    if (y < yy)
    {
        while (y != yy)
        {
            y++;
            arr[x][y] = '#';
        }
    }
    else
    {
        while (y != yy)
        {
            y--;
            arr[x][y] = '#';
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << arr[i][j];
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
    // cin >> tt;
    while (tt--)
        solve();

    return 0;
}