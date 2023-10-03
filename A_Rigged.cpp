#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({b, a});
    }
    for (int i = 1; i < n; ++i)
    {
        if (v[i].second >= v[0].second)
        {
            if (v[i].first >= v[0].first)
            {
                cout << -1 << endl;
                return;
            }
        }
    }
    cout << v[0].second - 1 << endl;
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