#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int arr[n];
    vector<pair<int, int>> v;
    vector<bool> vis(n, false);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    v.push_back({1, n});
    if ((arr[0] + arr[n - 1]) & 1)
    {
        arr[n - 1] = arr[0];
    }
    else
    {
        arr[0] = arr[n - 1];
    }
    for (int i = 1; i < n - 1; ++i)
    {
        if ((arr[0] + arr[i]) & 1)
        {
            vis[i] = true;
            v.push_back({1, i + 1});
        }
    }
    for (int i = n - 2; i >= 1; --i)
    {
        if (vis[i])
            continue;
        if ((arr[n - 1] + arr[i]) % 2 == 0)
        {
            v.push_back({i + 1, n});
        }
    }
    cout << v.size() << endl;
    for (auto val : v)
    {
        cout << val.first << ' ' << val.second << endl;
    }
}
int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}