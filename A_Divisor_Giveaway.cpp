#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    ll n, k;
    cin >> n >> k;
    for (int i = 1;; i++)
    {
        ll x = i * k;
        if (x > n)
        {
            cout << x << endl;
            return;
        }
    }
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