#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> adj[n];
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    string a, b;
    for (int i = 0; i < n; i++)
    {
        if (adj[i].size() == 1)
        {
            a.push_back('a');
        }
        else
        {
            a.push_back('b');
        }

        if (adj[i].size() == 1)
        {
            b.push_back('b');
        }
        else
        {
            b.push_back('a');
        }
    }
    if (a < b)
    {
        cout << a << '\n';
    }
    else
    {
        cout << b << '\n';
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}