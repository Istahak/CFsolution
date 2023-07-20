#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    ll n, k, d, w;
    cin >> n >> k >> d >> w;
    vector<int> t(n);
    for (auto &i : t)
        cin >> i;
    ll ans = 0;
    int j = 0;
    while (j < n)
    {
        ll f = t[j] + w + d;
        int ok = k;
        ans++;
        while (t[j] <= f && ok && j < n)
        {
            j++;
            ok--;
        }
    }
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