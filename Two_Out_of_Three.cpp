#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> mp;
    for (auto &x : v)
        cin >> x, mp[x]++;
    int c2 = 0, c3 = 0;

    vector<int> ans(n, -1);
    int st = 0;
    for (int i = 1; i <= 100; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (v[j] == i)
            {
                cnt++;
            }
        }
        if (cnt == 1)
        {
            for (int j = 0; j < n; j++)
            {
                if (v[j] == i)
                {
                    ans[j] = 1;
                }
            }
        }
        else if (cnt)
        {
            if (st)
            {
                int ccc = 0;
                for (int j = 0; j < n; j++)
                {
                    if (v[j] == i)
                    {
                        if (ccc == 0)
                            ans[j] = 2, c2++;
                        else
                            ans[j] = 1;
                        ccc++;
                    }
                }
                st = 0;
            }
            else
            {
                int ccc = 0;
                for (int j = 0; j < n; j++)
                {
                    if (v[j] == i)
                    {
                        if (ccc == 0)
                            ans[j] = 3, c3++;
                        else
                            ans[j] = 1;
                        ccc++;
                    }
                }
                st = 1;
            }
        }
    }
    if (c2 && c3)
    {
        for (auto &x : ans)
            cout << x << ' ';
        cout << '\n';
    }
    else
    {
        cout << -1 << '\n';
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