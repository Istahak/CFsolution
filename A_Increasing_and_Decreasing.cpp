#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int x, y, n;
    cin >> x >> y >> n;
    vector<int> v(n);
    v[n - 1] = y;
    int cur = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        v[i] = v[i + 1] - cur;
        cur++;
        
    }
    if (v.front() < x)
    {
        cout << -1 << endl;
    }
    else
    {
        v[0] = x;
        for (auto ans : v)
            cout << ans << ' ';
        cout << endl;
    }
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