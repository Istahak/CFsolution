#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    ll n, a, b;
    cin >> n >> a >> b;
    bool ok = false;
    ll cur = 1;
    while (cur <= n)
    {
        if (cur % b == n % b)
        {
            ok = true;
            break;
        }
        if (a == 1)
            break;
        cur *= a;
    }
    cout << (ok ? "Yes" : "No") << endl;
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