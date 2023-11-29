#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    string x, s;
    cin >> x >> s;
    int ans = 0;
    while (x.size() < m)
    {
        x += x;
        ans++;
    }
    if (x.find(s) != string::npos)
    {
        cout << ans << '\n';
        return;
    }
    x += x;
    ans++;
    if (x.find(s) != string::npos)
    {
        cout << ans << '\n';
        return;
    }
    cout << -1 << '\n';
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