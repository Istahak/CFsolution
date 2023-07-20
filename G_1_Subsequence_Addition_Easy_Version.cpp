#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;
    sort(v.begin(), v.end());
    bool ok = true;
    if (v[0] != 1)
        ok = false;
    ll sbsum = 1;
    for (int i = 1; i < n; i++)
    {
        if (v[i] > sbsum)
            ok = false;
        sbsum += v[i];
    }
    cout << (ok ? "YES" : "NO") << endl;
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
