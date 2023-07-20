#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n + 2, 0);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    ll ans = 0, cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (v[i] < 2 * v[i + 1])
            cnt++;
        else
        {
            ans += max(0ll, cnt - k + 1);
            cnt = 0;
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
    cin >> t;
    while (t--)
    {

        solve();
    }

    return 0;
}