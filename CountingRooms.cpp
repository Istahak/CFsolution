#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
int n, m;
char grid[1005][1005];
bool vis[1005][1005];
void DFS(int x, int y)
{
    if (grid[x][y] == '#' || vis[x][y])
        return;
    vis[x][y] = true;
    DFS(x - 1, y);
    DFS(x + 1, y);
    DFS(x, y + 1);
    DFS(x, y - 1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n + 5; i++)
        for (int j = 0; j < m + 5; j++)
            grid[i][j] = '#';

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> grid[i][j];

    int connactedcomponent = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (grid[i][j] == '.' && !vis[i][j])
            {
                connactedcomponent++;
                DFS(i, j);
            }
        }

    cout << connactedcomponent << endl;

    return 0;
}
