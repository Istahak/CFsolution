#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    map<ll, ll> fr;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        v[i] = x;
        fr[x]++;
    }
    int q;
    cin >> q;
    while (q--)
    {
        ll x, y;
        cin >> x >> y;
        ll p = x * x - 4 * y;
        if (p < 0)
        {
            cout << 0 << ' ';
            continue;
        }
        ll d = sqrtl(p);
        if (d * d != p or (d + x) % 2 == 1)
        {
            cout << 0 << ' ';
            continue;
        }
        ll X = (x + d) / 2, Y = (x - d) / 2;
        if (X == Y)
        {
            cout << fr[X] * (fr[X] - 1) / 2 << ' ';
        }
        else
        {
            cout << fr[X] * fr[Y] << ' ';
        }
    }
    cout << endl;
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