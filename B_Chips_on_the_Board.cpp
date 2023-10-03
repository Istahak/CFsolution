#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    ll n;
    cin >> n;
    ll arr[n];
    ll brr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    for (int i = 0; i < n; ++i)
        cin >> brr[i];
    sort(arr, arr + n);
    sort(brr, brr + n);
    ll ans1 = accumulate(arr, arr + n, 0LL) + (n * brr[0]);
    ll ans2 = accumulate(brr, brr + n, 0LL) + (n * arr[0]);
    cout << min(ans1, ans2) << endl;
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