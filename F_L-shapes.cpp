#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
char c[101][101];
int cnt = 0;
bool visited[101][101];
void DFS(int x, int y)
{
    if (c[x][y] == '.')
        return;
    if (visited[x][y])
        return;
    visited[x][y] = true;
    cnt++;
    DFS(x, y - 1);
    DFS(x, y + 1);
    DFS(x - 1, y);
    DFS(x + 1, y);
    DFS(x - 1, y - 1);
    DFS(x + 1, y + 1);
    DFS(x - 1, y + 1);
    DFS(x + 1, y - 1);
}
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> c[i][j];

    int conactedcomponent = 0;
    bool flag = false;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (c[i][j] == '*')
            {
                if (!visited[i][j])
                {
                    conactedcomponent++;
                    DFS(i, j);
                    if (cnt != 3)
                    {
                        flag = true;
                    }
                    // cout << cnt << endl;
                    cnt = 0;
                }
            }
        }
    if (flag)
    {
        cout << "NO" << endl;
        return;
    }
    // cout << conactedcomponent << endl;
    int Lshap = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (c[i][j] == '*')
            {
                if (c[i][j - 1] == '*' && c[i - 1][j] == '*')
                    Lshap++;
                if (c[i][j - 1] == '*' && c[i + 1][j] == '*')
                    Lshap++;
                if (c[i][j + 1] == '*' && c[i - 1][j] == '*')
                    Lshap++;
                if (c[i][j + 1] == '*' && c[i + 1][j] == '*')
                    Lshap++;
            }
        }
    // cout << Lshap << endl;
    cout << (conactedcomponent == Lshap ? "YES" : "NO") << endl;
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
        for (int i = 0; i < 101; i++)
            for (int j = 0; j < 101; j++)
            {
                c[i][j] = '.';
            }
        for (int i = 0; i < 101; i++)
            for (int j = 0; j < 101; j++)
            {
                visited[i][j] = false;
            }

        solve();
    }

    return 0;
}