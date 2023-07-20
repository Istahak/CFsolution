#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 2e5 + 10;
// vector<pair<int, char>> G[N];
map<pair<int, int>, vector<pair<int, int>>> G;
bool vis[N][2];
bool flag = false;
void dfs(int vertex, int col)
{
    vis[vertex][col] = true;
    if (G[{vertex, col}].size() != 2)
    {
        flag = true;
        return;
    }
    for (auto child : G[{vertex, col}])
    {
        if (!vis[child.first][child.second])
        {
            dfs(child.first, child.second);
        }
    }
    return;
}
int main()
{
    int g = 121 + 11, n = 11;
    int f = (((g / n) + n) / n) * n;
    cout << f << endl;
    return 0;
}