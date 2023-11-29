#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<string> v(n);
    for (auto &x : v)
        cin >> x;
    ll ans = 0;
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            int op1 = v[n - i - 1][n - j - 1];
            int op2 = v[n - j - 1][i];
            int op3 = v[i][j];
            int op4 = v[j][n - i - 1];
            ll mx = max({op1, op2, op3, op4});
            ans += 4ll * mx - op1 - op2 - op3 - op4;
        }
    }

    cout << ans << '\n';
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