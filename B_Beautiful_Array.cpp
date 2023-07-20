#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    ll n, k, b, s;
    cin >> n >> k >> b >> s;
    ll flag = (k - 1) * (n - 1);
    ll newsum = s - flag;
    ll flag2 = newsum / k;
    if (flag2 > b || b * k > s)
    {
        cout << -1 << endl;
        return;
    }
    ll x = k * (b + 1) - 1;
    // cout<<x<<endl;
    if (x > s)
    {
        cout << s << ' ';
        n -= 1;
        while (n--)
        {
            cout << 0 << ' ';
        }
        cout << endl;
        return;
    }
    cout << x << ' ';
    s -= x;
    // cout<<s<<endl;
    n--;
    k--;
    while (n--)
    {
        if (s > 0 && s >= k)
        {
            cout << k << ' ';
            s -= k;
        }
        else if (s > 0 && s < k)
        {
            cout << s << ' ';
            s = 0;
        }
        else
            cout << 0 << ' ';
    }
    cout << endl;
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