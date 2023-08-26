#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    vector<int> v(3);
    for (auto &x : v)
        cin >> x;
    sort(v.begin(), v.end());
    // cin >> a >> b >> c;
    cout << (v[2] + v[1] >= 10 ? "YES" : "NO") << endl;
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