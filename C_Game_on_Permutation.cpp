#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;
    set<int> a, b;
    b.insert(v[0]);
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        auto it = a.lower_bound(v[i]);
        auto itt = b.lower_bound(v[i]);
        if (it == a.begin() and itt != b.begin())
        {
            ans++;
            a.insert(v[i]);
        }
        b.insert(v[i]);
    }
    cout << ans << endl;
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