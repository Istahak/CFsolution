#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll p = 0, m = 0;
bool ok(ll x, ll y)
{
    ll k = (x - y);
    ll kk = m * x - p * y;
    //cout<<kk<<' '<<k<<endl;
    if ((kk <= 0 && k < 0) || (k > 0 && kk >= 0))
    {
        return kk % k == 0;
    }
    return false;
}
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (auto c : s)
    {
        c == '+' ? p++ : m++;
    }
    int q;
    cin >> q;
    while (q--)
    {
        ll x, y;
        cin >> x >> y;
        if (x == y)
        {
            cout << (p == m ? "YES" : "NO") << endl;
        }
        else
        {
            cout << (ok(x, y) && ok(y, x) ? "YES" : "NO") << endl;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    // cin >> tt;
    while (tt--)
        solve();

    return 0;
}