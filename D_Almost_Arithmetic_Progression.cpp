#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    if (n <= 2)
    {
        cout << 0 << endl;
        return;
    }
    ll ans = INT_MAX * 1LL;
    auto minpossible = [&](ll f, ll s)
    {
        ll curans = 0;
        ll d = s - f;
        for (int i = 0; i < n; i++)
        {
            ll aa = f + i * d;
            if (abs(aa - a[i]) > 1)
                return INT_MAX * 1LL;
            if (aa != a[i])
                curans++;
        }
        return curans;
    };
    ans = min(ans, minpossible(a[0], a[1]));
    ans = min(ans, minpossible(a[0] - 1, a[1]));
    ans = min(ans, minpossible(a[0] + 1, a[1]));
    ans = min(ans, minpossible(a[0], a[1] - 1));
    ans = min(ans, minpossible(a[0] - 1, a[1] - 1));
    ans = min(ans, minpossible(a[0] + 1, a[1] - 1));
    ans = min(ans, minpossible(a[0], a[1] + 1));
    ans = min(ans, minpossible(a[0] - 1, a[1] + 1));
    ans = min(ans, minpossible(a[0] + 1, a[1] + 1));

    cout << (ans == INT_MAX ? -1 : ans) << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}