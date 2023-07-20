#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v[i] *= x;
    }
    int f = v[0];
    vector<bool> used(n + 1, true);
    vector<int> ans;
    ans.push_back(1);
    used[1] = false;
    for (int i = 1; i < n; i++)
    {
        int y = v[i];
        bool ok = true;
        for (int j = 2; j <= n; j++)
        {
            if ((j * y) >= f && used[j])
            {
                ans.push_back(j);
                used[j] = false;
                ok = false;
                break;
            }
        }
        if (ok)
        {
            cout << "impossible" << endl;
            return;
        }
    }
    for (auto ans : ans)
        cout << ans << ' ';
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    // cin >> tt;
    while (tt--)
        solve();

    return 0;
}