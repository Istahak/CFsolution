#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    sort(v.begin(), v.end());
    ll presum = accumulate(v.begin(), v.end(), 0LL);
    ll nesum = v[n / 2 - 1] * (n + 1);
    ll val = nesum - presum;
    if (val <= v[n / 2 - 1])
    {
        cout << val << "\n";
        return;
    }
    nesum = v[n / 2] * (n + 1);
    val = nesum - presum;
    cout << val << "\n";
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