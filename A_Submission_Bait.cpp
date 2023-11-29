#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif

void solve()
{
    int n;
    cin >> n;
    deque<int> q;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        q.push_back(x);
    }
    int ans = 0;
    while (q.size() > 1)
    {
        int f = q.front();
        int l = q.back();
        q.pop_front();
        q.pop_back();
        if (f == l)
        {
            continue;
        }
        else if (f > l)
        {
            q.push_front(f - l);
            ans++;
        }
        else
        {
            q.push_back(l - f);
            ans++;
        }
    }
    cout << ans << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case " << cs << ": ";
        solve();
    }
    return 0;
}