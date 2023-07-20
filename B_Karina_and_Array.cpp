#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<ll> a, b;
    bool ok = false;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if (x > 0)
            a.push_back(x);
        else if (x < 0)
            b.push_back(abs(x));
        else
        {
            ok = true;
        }
    }
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    if (a.size() >= 2 and b.size() >= 2)
    {
        cout << max(a[0] * a[1], b[0] * b[1]) << endl;
    }
    else if (b.size() >= 2)
    {
        cout << b[0] * b[1] << endl;
    }
    else if (a.size() >= 2)
    {
        cout << a[0] * a[1] << endl;
    }
    else
    {
        if (ok)
            cout << 0 << endl;
        else
            cout << a[0] * b[0] * (-1) << endl;
    }
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