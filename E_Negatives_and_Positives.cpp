#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    ll ans = 0, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i] <= 0)
            cnt++, v[i] = -v[i];
        ans += v[i];
    }
    if (cnt & 1)
    {
        int mi = *min_element(v.begin(), v.end());
        // mi = -mi;
        cout << ans - 2ll * mi << endl;
    }
    else
    {
        cout << ans << endl;
    }
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