#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    if (n % 2 == 0)
    {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    vector<pair<int, int>> ans;
    int x = 2 * n;

    for (int i = 2; i <= n; i += 2)
    {
        ans.push_back({i, x});
        x--;
    }
    for (int i = 1; i <= n; i += 2)
    {
        ans.push_back({i, x});
        x--;
    }
    sort(ans.begin(), ans.end());
    for (auto [x, y] : ans)
    {
        cout << x << ' ' << y << endl;
    }
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