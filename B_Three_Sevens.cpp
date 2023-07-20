#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int m;
    cin >> m;
    vector<int> st[m + 1];
    map<int, int> mp;
    for (int i = 1; i <= m; i++)
    {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            st[i].push_back(x);
            mp[x]++;
        }
    }
    vector<int> ans(m + 1, 0);
    bool ok = true, ok1 = false;
    for (int i = 1; i <= m; i++)
    {
        ok = true;
        for (auto x : st[i])
        {
            if (mp[x] == 1 && ok)
            {
                ans[i] = x;
                mp[x]--;
                ok = false;
            }
            else
            {
                mp[x]--;
            }
        }
        if (ans[i] == 0)
        {
            ok1 = true;
            break;
        }
    }
    if (ok1)
    {
        cout << -1 << endl;
        return;
    }
    for (int i = 1; i <= m; i++)
        cout << ans[i] << ' ';
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}
