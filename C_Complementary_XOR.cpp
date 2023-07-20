#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    bool ok = (a[0] == b[0]), flag = false;
    for (int i = 1; i < n; i++)
    {
        if ((a[i] == b[i]) != ok)
            flag = true;
    }
    if (flag)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == '1')
        {
            v.push_back({i + 1, i + 1});
            ok ^= 1;
        }
    }
    if (!ok)
    {
        v.push_back({1, 1});
        v.push_back({2, n});
        v.push_back({1, n});
    }
    cout << v.size() << endl;
    for (auto ans : v)
        cout << ans.first << ' ' << ans.second << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    cin >> t;
    while (t--)
    {

        solve();
    }

    return 0;
}