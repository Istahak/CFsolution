#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    ll n, k;
    cin >> n >> k;
    ll gc = __gcd(2ll, k);
    if (n % gc)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
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