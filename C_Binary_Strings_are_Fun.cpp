#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
const int M = 998244353;
// long long int a, b;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = 1;
    ll flag = 1;
    for (int i = 1; i < n; ++i)
    {
        if (s[i] != s[i - 1])
        {
            ans = (ans % M + 1) % M;
            flag = 1;
        }
        else
        {
            flag = ((flag % M) * 2) % M;

            ans = (ans % M + flag % M) % M;
        }
    }
    cout << ans << endl;
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