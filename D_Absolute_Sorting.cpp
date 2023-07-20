#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n;
    cin >> n;

    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;
    ll l = 0, r = 1e9;
    for (int i = 1; i < n; i++)
    {
        if (v[i - 1] > v[i])
        {
            l = max(l, (v[i - 1] + v[i] + 1) / 2);
        }
        else if (v[i - 1] < v[i])
        {
            r = min(r, (v[i - 1] + v[i]) / 2);
        }
        if (l > r)
        {
            cout << "-1" << endl;
            return;
        }
    }
    cout << min(l,r) << endl;
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