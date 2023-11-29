#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif

void solve()
{
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    auto match = [&](int id)
    {
        int cc = 0;
        for (int i = id; i < m + id; i++)
        {

            if (s[i] != '#' and s[i] != t[i - id])
                return false;
            cc += (s[i] != '#');
        }
        return cc > 0;
    };
    queue<int> q;
    for (int i = 0; i < n - m + 1; i++)
    {
        if (match(i))
        {
            q.emplace(i);
        }
    }
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        // debug(),dbg(s);
        for (int i = cur; i < cur + m; i++)
            s[i] = '#';
        for (int i = max(0, cur - 4); i <= min(n - 1, cur + m - 1) and i < n - m + 1; i++)
        {
            if (match(i))
            {
                q.emplace(i);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (s[i] != '#')
        {
            cout << "No" << '\n';
            return;
        }
    }
    cout << "Yes" << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case " << cs << ": ";
        solve();
    }
    return 0;
}