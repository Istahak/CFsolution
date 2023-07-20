#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    string s[2];
    cin >> s[0] >> s[1];
    int dif = 0;
    for (int i = 0; i < (int)s[0].size(); i++)
    {
        if (s[0][i] != s[1][i]) dif++;
    }
    int q, t;
    cin >> t >> q;
    queue<pair<int, int>> blocked;
    for (int i = 1; i <= q; i++)
    {
        if (!blocked.empty())
        {
            auto [x, y] = blocked.front();
            if (y + t == i)
            {
                blocked.pop();
                if (s[0][x] != s[1][x])
                    dif++;
            }
        }
        int ty;
        cin >> ty;
        if (ty == 1)
        {
            int x;
            cin >> x;  x--;
            if (s[0][x] != s[1][x])  dif--;
            blocked.emplace(x, i);
        }
        if (ty == 2)
        {
            int p, q, x, y;
            cin >> p >> q >> x >> y; p--, q--, x--, y--;
            if (s[0][q] != s[1][q]) dif--;
            if (s[0][y] != s[1][y]) dif--;
            swap(s[p][q], s[x][y]);
            if (s[0][q] != s[1][q]) dif++;
            if (s[0][y] != s[1][y]) dif++;
        }
        if (ty == 3)
        {
            cout << (dif ? "NO" : "YES") << endl;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}