#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
void solve()
{
    int n, q;
    cin >> n >> q;
    ll sum = 0, odd = 0, even = 0;
    int i=n;
    while (i--)
    {
        ll x;
        cin >> x;
        sum += x;
        x & 1 ? odd++ : even++;
    }
    while (q--)
    {
        ll x, y;
        cin >> x >> y;
        if (x)
        {
            sum += (odd * y);
            if (y&1)
            {
                odd = 0;
                even = n;
            }
        }
        else
        {
            sum += (even * y);
            if (y & 1)
            {
                even = 0;
                odd = n;
            }
        }
        cout << sum << endl;
    }
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
