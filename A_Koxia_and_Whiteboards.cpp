#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;

    ll ans = 0;
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        sort(a.begin(), a.end());
        a[0] = b[i];
    }
    for (int i = 0; i < n; i++)
        ans += a[i];
    cout << ans << endl;
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