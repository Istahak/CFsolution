#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    ll n;
    cin >> n;
    for (ll i = 2; i * i <= n; i++)
    {
        ll cur = 1;
        while (cur <= n)
        {
            if (cur == n)
            {
                cout << "YES" << endl;
                return;
            }
            cur = cur * i + 1;
        }
    }
    cout << "NO" << endl;
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