#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int arr[n+1][n];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < n; j++)
            cin >> arr[i][j];
    vector<int> ans;
    vector<bool> used(n + 1, true);
    used[0] = false;
    for (int i = 1; i < n; i++)
    {
        map<int, int> mp;
        for (int j = 1; j <= n; j++)
        {
            mp[arr[j][i]]++;
        }
        vector<int>f;
        for (auto [x, y] : mp)
        {
            f.push_back(x);
        }
        if (mp[f[0]] < mp[f[1]])
            swap(f[0], f[1]);
       // cout << f[0] << ' ' << f[1] << endl;
        if (used[f[0]])
        {
            ans.push_back(f[0]);
            used[f[0]] = false;
        }
        if (used[f[1]])
        {
            ans.push_back(f[1]);
            used[f[1]] = false;
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
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}