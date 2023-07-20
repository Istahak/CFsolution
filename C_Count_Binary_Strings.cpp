#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
const int M = 998244353;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n + 1);
    int x = n;
    int a[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            cin >> a[i][j];
        }
        x--;
    }
    x = n;
    for (int i = 1; i <= n; i++)
    {
        int mx = INT_MIN;
        for (int j = 1; j <= x; j++)
        {

            mx = max(a[j][i], mx);
        }
        v[i] = mx;
        x--;
    }
    ll ans = 2;
    vector<int> flag;

    for (int i = 1; i <= n; i++)
    {
        if (v[i] == 0)
            continue;
        flag.push_back(v[i]);
    }
    if (!is_sorted(flag.begin(), flag.end()) || v[1] == 2)
    {
        cout << 0 << endl;
        return;
    }
    int p = 0;
    for (int i = 2; i <= n; i++)
    {
        if (v[i] == 0)
            ans = ((ans % M) * 2) % M;
        if (v[i] == 1)
            ans = 2;

        if (v[i] == 2)
        {
            if (p)
            {
                ans = ((ans % M) * 2) % M;
            }
            else
            {
                ans = (ans * 2) % M;
                ans = (ans - 2 + M) % M;
            }
            p = 2;
        }
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    // cin >> t;
    while (t--)
    {

        solve();
    }

    return 0;
}