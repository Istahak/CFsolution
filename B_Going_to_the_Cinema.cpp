#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    bool ok = false;
    for (auto &i : v)
    {
        cin >> i;
        if (i == 0)
            ok = true;
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (v[i] < (i + 1))
        {
            if (v[i + 1] >= (i + 2))
                ans += 1;
        }
    }
    ok ? ans += 1 : ans += 2;

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