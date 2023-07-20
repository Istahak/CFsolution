#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<ll> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    if (n & 1)
    {
        cout << "YES" << endl;
        return;
    }
    if (is_sorted(v.begin(), v.end()))
    {
        cout << "YES" << endl;
        return;
    }
    if (n == 2)
    {
        cout << "NO" << endl;
        return;
    }
    ll f = 0;
    for (int i = n - 1; i >= 2; i--)
    {
        if (v[i] > v[i + 1])
        {
            if (~(n - i) & 1)
            {
                continue;
            }
            f = abs(v[i + 1] - v[i]);
            v[i - 1] -= f;
            v[i] -= f;
        }
        else
        {
            f = abs(v[i + 1] - v[i]);
            v[i - 1] += f;
            v[i] += f;
        }
    }

    cout << (v[1] <= v[2] ? "YES" : "NO") << endl;
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