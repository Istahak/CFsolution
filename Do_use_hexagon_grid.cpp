#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
int grid[2005][2005];
int vis[2005][2005];

void DSF(int x, int y)
{
    if (grid[x][y] == 0 || vis[x][y] == 1)
        return;
    vis[x][y] = 1;
    DSF(x - 1, y - 1);
    DSF(x - 1, y);
    DSF(x, y - 1);
    DSF(x, y + 1);
    DSF(x + 1, y);
    DSF(x + 1, y + 1);
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
        int x, y;
        cin >> x >> y;
        x += 1000, y += 1000;
        grid[x][y] = 1;
    }
    int connected_components = 0;
    for (int i = 0; i < 2005; i++)
        for (int j = 0; j < 2005; j++)
        {
            if (grid[i][j] == 1 && vis[i][j] == 0)
            {
                connected_components++;
                DSF(i, j);
            }
        }
    cout << connected_components << endl;
    return 0;
}
