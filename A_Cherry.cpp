#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;
    ll ans = 0;
    for (int i = 1; i < n; i++)
    {
        ans = max(ans, v[i - 1] * v[i]);
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    cin >> t;
    while (t--)
    {

        solve();
    }

    return 0;
}
