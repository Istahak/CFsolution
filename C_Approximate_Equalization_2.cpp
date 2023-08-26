#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    ll sum = accumulate(v.begin(), v.end(), 0LL);
    ll everyval = sum / n;
    ll numofin = sum % n;
    sort(v.begin(), v.end());
    ll op = 0;
    while (numofin--)
    {
        op += abs((v.back() - (everyval + 1)));
        v.pop_back();
    }
    for (auto x : v)
    {
        op += abs(x - everyval);
    }
    cout << op / 2 << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
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