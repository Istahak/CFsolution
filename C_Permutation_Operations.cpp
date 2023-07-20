#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n + 1);
    vector<pair<int, int>> vf;
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    vf.push_back({0, 1});
    for (int i = n; i > 1; i--)
    {
        if (v[i - 1] > v[i])
        {
            vf.push_back({v[i - 1] - v[i], i});
        }
        else
        {
            vf.push_back({0, i});
        }
    }
    sort(vf.begin(), vf.end());
    for (auto i : vf)
    {
        cout << (i.first == 0 ? 1 : i.second) << ' ';
    }
    cout << endl;
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
