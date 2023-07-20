#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 1; i < (3 * (n / 2)); i += 3)
    {
        v.push_back({i, 3 * n - i});
    }

    if (n & 1)
    {
        v.push_back({n / 2 * 3 + 1, n / 2 * 3 + 2});
    }
    cout << v.size() << endl;
    for (auto i : v)
    {
        cout << i.first << ' ' << i.second << endl;
    }
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