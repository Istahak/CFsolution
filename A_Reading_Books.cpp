#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    sort(b.begin(), b.end());
    int cur = 0;
    ll curtime = 0;
    ll covertime = 0;
    for (int i = 0; i < n; i++)
    {
        curtime += a[i];
        while (cur < m and (curtime - b[cur]) >= 0)
        {
            curtime -= b[cur++];
        }
        cout << cur << ' ';
    }
    cout << endl;
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