#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int mod = 1e9 + 7;
void solve()
{
    ll n;
    cin >> n;
    __uint128_t Ans = 0;
    ll cur = 1;
    for (int i = 1;; i++)
    {
        Ans += (n / cur);
        cur = lcm(cur, i);
        if (cur > n)
            break;
    }
    int ans = Ans % mod;
    cout << ans << endl;
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