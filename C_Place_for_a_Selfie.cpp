#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;
    sort(v.begin(), v.end());
    while (m--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        auto it = upper_bound(v.begin(), v.end(), b);
        if (it != v.end())
        {
            ll x = (*it);
            ll tem = (b - x) * (b - x) - 4 * a * c;
            if (tem < 0)
            {
                cout << "YES" << endl;
                cout << x << endl;
                continue;
            }
        }

        if (it != v.begin())
        {
            it--;
            ll x = (*it);
            ll tem = (b - x) * (b - x) - 4 * a * c;
            if (tem < 0)
            {
                cout << "YES" << endl;
                cout << x << endl;
                continue;
            }
        }
        cout << "NO" << endl;
    }
    cout << endl;
}
int main()
{

    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }

    return 0;
}