#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
char grid[1005][1005];
bool vis[1005][1005];
int pre[1005][1005];
int n, m;
int dx[4] = {-1, 0, 1, 0};

int dy[4] = {0, 1, 0, -1};

string sd = "URDL";
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;

    queue<pair<int, int>> q;
    pair<int, int> begin, end;
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {

            cin >> grid[i][j];

            if (grid[i][j] == 'A')
            {

                begin = make_pair(i, j);
            }
            if (grid[i][j] == 'B')
            {

                end = make_pair(i, j);
            }
        }
    }
    q.push(begin);

    vis[begin.first][begin.second] = true;

    while (!q.empty())
    {
        pair<int, int> u = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {

            pair<int, int> v = make_pair(u.first + dx[i], u.second + dy[i]);

            if (v.first < 0 || v.first >= n || v.second < 0 || v.second >= m)
                continue;

            if (grid[v.first][v.second] == '#')
                continue;

            if (vis[v.first][v.second])
                continue;

            vis[v.first][v.second] = true;

            pre[v.first][v.second] = i;

            q.push(v);
        }
    }
    if (!vis[end.first][end.second])
    {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;

    vector<int> pass;

    while (end != begin)
    {

        int p = pre[end.first][end.second];

        pass.push_back(p);

        end = make_pair(end.first - dx[p], end.second - dy[p]);
    }

    reverse(pass.begin(), pass.end());

    cout << pass.size() << endl;

    for (auto c : pass)
    {

        cout << sd[c];
    }

    cout << endl;

    return 0;
}
