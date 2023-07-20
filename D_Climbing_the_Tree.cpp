#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{

    int q;
    cin >> q;
    ll mx = 1e18, mi = 0;
    while (q--)
    {
        int ty;
        cin >> ty;
        if (ty == 1)
        {
            ll a, b, n;
            cin >> a >> b >> n;
            ll curmx, curmi;
            if (n == 1)
            {
                curmx = b, curmi = 1;
            }
            else
            {
                curmx = a * n - b * (n - 1);
                curmi = a * (n - 1) - b * (n - 2) + 1;
            }
            if (mi > curmx || mx < curmi)
            {
                cout << 0 << ' ';
            }
            else
            {
                mi = curmi;
                mx = curmx;
                cout << 1 << ' ';
            }
        }
        else
        {
            ll a, b;
            cin >> a >> b;
            ll ans = (mx - b) / (a - b);
            if ((mx - b) % (a - b))
                ans++;
            // cout << ans << ' ';
            ll ans1 = (mi - b) / (a - b);
            if ((mi - b) % (a - b))
                ans1++;
            if (ans == ans1)
                cout << ans << ' ';
            else
                cout << -1 << ' ';
            // cout << ans << ' ' << ans1 << endl;
            //  cout<<mi<<' '<<mx<<endl;
        }
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