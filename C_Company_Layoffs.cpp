#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n), pre(n + 1, 0);
    for (auto &i : v)
        cin >> i;
    sort(v.begin(), v.end());
    pre[0] = 0;
    for (int i = 0; i < n; i++)
    {
        pre[i + 1] = pre[i] + v[i];
    }
    while (m--)
    {
        int x;
        cin >> x;
        auto it = upper_bound(v.begin(), v.end(), x) - v.begin();
        cout << x * (n - it) + pre[it] << endl;
    }
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