#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    ll n;
    string s;
    cin >> n >> s;
    ll zero = 0, one = 0;
    for (auto c : s)
        c == '1' ? one++ : zero++;
    ll l = (1 << one);
    ll r = (1 << n) - (1 << zero) + 1;
    // cout<<l<<' '<<r<<endl;
    for (ll i = l; i <= r; i++)
        cout << i << ' ';
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    // cin >> t;
    while (t--)
    {

        solve();
    }

    return 0;
}