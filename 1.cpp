#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 2e5 + 10;
const ll M = 1e9 + 7;
void solve()
{
    ll n, m, d;
    cin >> n >> m >> d;
    vector<ll> arr(n);
    vector<ll> brr(m);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    for (int i = 0; i < m; ++i)
        cin >> brr[i];
    sort(arr.begin(), arr.end());
    sort(brr.begin(), brr.end());
    ll ans = -1;
    for (int i = 0; i < n; ++i)
    {
        ll curr = arr[i];
        int it = upper_bound(brr.begin(), brr.end(), arr[i] + d) - brr.begin();
        it--;
        if (abs(brr[it] - arr[i]) <= d && it >= 0)
        {
            // cout << (*it) << endl;
            ans = max(ans, arr[i] + (brr[it]));
        }
    }
    for (int i = 0; i < m; ++i)
    {
        ll curr = brr[i];
        int it = upper_bound(arr.begin(), arr.end(), brr[i] + d) - arr.begin();
        it--;
        if (abs(arr[it] - brr[i]) <= d && it >= 0)
        {
            ans = max(ans, brr[i] + (arr[it]));
        }
    }
    cout << ans << endl;
}
int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}